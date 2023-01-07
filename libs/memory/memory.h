#ifndef _MEMORY_H
#define _MEMORY_H 1

#include <stddef.h>

void* malloc_(size_t size);
void free_(void* ptr);

void* calloc_(size_t number, size_t size);

#endif // _MEMORY_H