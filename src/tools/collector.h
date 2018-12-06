#ifndef COLLECTOR
#define COLLECTOR
#include <stdlib.h>
#include <stdio.h>

typedef struct Collector_t
{
    void **item;
    int pos;
    int size;
} Collector;

Collector *collectorInit();
void *malloc_collect(Collector *c, size_t size);
void collectorFree(Collector *c);
void *realloc_collect(Collector *c, void* ptr, size_t size);

#endif
