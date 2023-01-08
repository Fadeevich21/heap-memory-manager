#ifndef _CHUNK_H
#define _CHUNK_H 1

#include <stddef.h>

struct Chunk;
typedef struct Chunk Chunk;

struct Chunk {
    size_t allocated_size;
    size_t used_size;
    struct {
        unsigned int is_mmap : 1;
        unsigned int is_free : 1;
    } flags;
    Chunk* prev_chunk;
    Chunk* next_chunk;
};

void init_chunk(Chunk* const chunk,
                const size_t allocated_size,
                const size_t used_size);
int is_mmap_chunk(const Chunk* const chunk);
int is_free_chunk(const Chunk* const chunk);

#endif // _CHUNK_H