#ifndef _MEMORY_H
#define _MEMORY_H 1

#include <stddef.h>

void* calloc_(size_t count_elements, size_t size);
void* malloc_(size_t size);
void free_(void* ptr);

#endif // _MEMORY_H