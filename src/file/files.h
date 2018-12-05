/**
* @file files.h
* @brief This header file will contain all required
* definitions and basic utilities functions to read and load a file into a char**.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef FILES
#define FILES

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../tools/tool.h"

int countLinesInFile(FILE *f);

char **getAllLines(char *path, int *nbLines, Collector *c);

#endif
