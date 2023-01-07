#include "chunk.h"

#define ALIGN_DOWN(base, align) ((base) & -((__typeof__(base)) (align)))

void init_chunk(Chunk* const chunk, const size_t size) {
    set_size_chunk(chunk, size);
    chunk->flags.is_free = 0;
    chunk->flags.is_mmap = 0;
    chunk->next_chunk = NULL;
    chunk->prev_chunk = NULL;
}

size_t get_size_chunk(const Chunk* const chunk) {
    return chunk->size & ~0x3UL;
}

size_t get_flags_chunk(const Chunk* const chunk) {
    return chunk->flags.is_mmap << 1 | chunk->flags.is_free;
}

void set_size_chunk(Chunk* const chunk, const size_t size) {
    chunk->size = ALIGN_DOWN(size, 8) | get_flags_chunk(chunk);
}

int is_mmap_chunk(const Chunk* const chunk) {
    return chunk->flags.is_mmap;
}

int is_free_chunk(const Chunk* const chunk) {
    return chunk->flags.is_free;
}
