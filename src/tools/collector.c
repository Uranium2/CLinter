/**
* @file collcetor.c
* @brief This c file will contain all functions to create and manipulate a Collector (Garbage Collector)
*
* @author Antoine TAVERNIER
*
* @date 05/12/2018
*/

#include "collector.h"

/**
 * @brief Initialize a Garbage Collector to store pointers
 * 
 * @return Collector* Collector that stores pointers
 */
Collector *collectorInit()
{
    Collector *c = malloc(sizeof(Collector));
    c->size = 1;
    c->pos = 0;
    c->item = malloc(sizeof(void *) * c->size);
    return c;
}

/**
 * @brief Extends the size of the Garbage collector list
 * 
 * @param c Collector that stores pointers
 */
void collect_extends(Collector *c)
{
    c->size = c->size * 2;
    c->item = realloc(c->item, sizeof(void *) * c->size);
}

/**
 * @brief Wrapper of malloc to store pointer in the Garbage Collector
 * 
 * @param c Collector that stores pointers
 * @param ptr Pointer to realloc
 * @return void* Pointer after realloc
 */
void *malloc_collect(Collector *c, size_t size)
{
    if (c->size == c->pos)
        collect_extends(c);
    void *p = malloc(size);
    c->item[c->pos] = p;
    c->pos++;
    return p;
}

/**
 * @brief Wrapper of realloc to store pointer in the Garbage Collector
 * 
 * @param c Collector that stores pointers
 * @param ptr Pointer to realloc
 * @param size Size to give to the new pointer
 * @return void* Pointer after realloc
 */
void *realloc_collect(Collector *c, void *ptr, size_t size)
{
    if (c->size == c->pos)
        collect_extends(c);
    void *p = realloc(ptr, size);
    c->item[c->pos] = p;
    c->pos++;
    return p;
}

/**
 * @brief Free all pointers in the Garbage collector
 * 
 * @param c Collector that stores pointers
 */
void collectorFree(Collector *c)
{

    for (int i = 0; i < c->pos; i++)
    {
        free(c->item[i]);
    }
    free(c->item);
    free(c);
}