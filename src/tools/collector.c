#include "collector.h"

Collector *collectorInit()
{
    Collector *c = malloc(sizeof(Collector));
    c->size = 10000;
    c->pos = 0;
    c->item = malloc(sizeof(void *) * c->size);
    return c;
}

void *malloc_collect(Collector *c, size_t size)
{
    void *p = malloc(size);
    c->item[c->pos] = p;
    c->pos++;
    return p;
}

void *realloc_collect(Collector *c, void* ptr, size_t size)
{
    void *p = realloc(ptr, size);
    c->item[c->pos] = p;
    c->pos++;
    return p;
}

void collectorFree(Collector *c)
{

    for (int i = 0; i < c->pos  ; i++)
    {
        free(c->item[i]);
    }
    free(c->item);
    free(c);
}