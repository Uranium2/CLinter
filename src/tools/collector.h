/**
* @file collector.h
* @brief Header file of collector
* @author Antoine TAVERNIER.
* @date 05/12/2018
*/

#ifndef COLLECTOR
#define COLLECTOR
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Structure to store pointers
 * 
 */
typedef struct Collector_t
{
    void **item; /**< The list of pointers. */
    int pos;     /**< The position in the list. */
    int size;    /**< The size of the list. */
} Collector;

Collector *collectorInit();
void *malloc_collect(Collector *c, size_t size);
void collectorFree(Collector *c);
void *realloc_collect(Collector *c, void *ptr, size_t size);

#endif
