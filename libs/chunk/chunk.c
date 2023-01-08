#include "chunk.h"

void init_chunk(Chunk* const chunk,
                const size_t allocated_size,
                const size_t used_size) {
    chunk->allocated_size = allocated_size;
    chunk->used_size = used_size;
    chunk->flags.is_free = 0;
    chunk->flags.is_mmap = 0;
    chunk->next_chunk = NULL;
    chunk->prev_chunk = NULL;
}

int is_mmap_chunk(const Chunk* const chunk) {
    return chunk->flags.is_mmap;
}

int is_free_chunk(const Chunk* const chunk) {
    return chunk->flags.is_free;
}
