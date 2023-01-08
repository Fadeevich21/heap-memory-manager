#include "memory.h"
#include <stdint.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>
#include "../messages_to_console/messages_to_console.h"
#include "../chunk/chunk.h"

#define MEMORY_PTR(chunk_ptr) ((void*) (((char*)chunk_ptr) + sizeof(Chunk)))
#define CHUNK_PTR(memory_ptr) ((void*) (((char*)memory_ptr) - sizeof(Chunk)))
#define ALLOCATE_SIZE(memory_size) (memory_size + sizeof(Chunk))
#define MEMORY_SIZE(allocate_size) (allocate_size - sizeof(Chunk))

#define SIZE_32MEGABYTES 33554432

Chunk* chunk_head = NULL;

void* malloc_mmap(size_t size) {
    Chunk* chunk_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE,
                            MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (chunk_ptr == MAP_FAILED) {
        PRINT_ERROR("Память не выделена! Код ошибки: %d", errno);
        return NULL;
    }
    init_chunk(chunk_ptr, size, size);
    chunk_ptr->flags.is_mmap = 1;
    
    return MEMORY_PTR(chunk_ptr);
}

void* malloc_(size_t size) {
    size_t allocated_size = ALLOCATE_SIZE(size);
    if (allocated_size > SIZE_32MEGABYTES) {
        return malloc_mmap(allocated_size);
    }

    Chunk* chunk_ptr = chunk_head;
    while (chunk_ptr != NULL) {
        if (is_free_chunk(chunk_ptr) && chunk_ptr->allocated_size >= allocated_size) {
            chunk_ptr->flags.is_free = 0;
            chunk_ptr->used_size = allocated_size;
            return MEMORY_PTR(chunk_ptr);
        }
        chunk_ptr = chunk_ptr->next_chunk;
    }

    chunk_ptr = sbrk(allocated_size);
    if (chunk_ptr != (void*) -1) {
        init_chunk(chunk_ptr, allocated_size, allocated_size);
        if (chunk_head != NULL) {
            chunk_ptr->next_chunk = chunk_head->next_chunk;
            chunk_head->prev_chunk = chunk_ptr;
        } else {
            chunk_head = chunk_ptr;
        }
        return MEMORY_PTR(chunk_ptr);
    }
    PRINT_ERROR("Выделение памяти не получилось");
    return NULL;
}

void* calloc_(size_t number, size_t size) {
    return malloc_(number * size);
}

void free_(void* ptr) {
    if (ptr == NULL) {
        PRINT_DBG("Указатель пустой");
        return;
    }

    Chunk* chunk_ptr = CHUNK_PTR(ptr);
    if (is_free_chunk(chunk_ptr)) {
        PRINT_WARNING("Для данного указателя не была выделена память");
        return;
    }

    if (is_mmap_chunk(chunk_ptr)) {
        int munmap_return = munmap(chunk_ptr,
                                   ALLOCATE_SIZE(chunk_ptr->allocated_size));
        if (munmap_return == -1) {
            PRINT_ERROR("Произошла ошибка при очистке памяти: %d", munmap_return);
        }
    } else {
        chunk_ptr->flags.is_free = 1;
        chunk_ptr->used_size = 0;
    }
}