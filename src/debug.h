/**
* @file debug.h
* @brief This header file will contain all required tools for debugging and displaying what is
* useful for the well-being of the development
* @author Théo Huchard
* @date 17/11/2018
*/
#ifndef DEBUG
#define DEBUG

#include <stdlib.h>
#include "../vendor/dirent.h"
#include <stdio.h>
#include <string.h>

void debugStruct(struct dirent *s);

#endif //DEBUG
