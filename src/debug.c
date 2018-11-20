/**
* @file debug.c
* @brief This C file contains all functions for debugging
* @author Théo Huchard
* @date 17/11/2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "debug.h"
#include "../vendor/dirent.h"

void debugStruct(struct dirent *s) {
    printf("Name : %s", s->d_name);
    EXIT_FAILURE;
}
