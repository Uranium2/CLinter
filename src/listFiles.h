/**
* @file listFiles.h
* @brief This header file will contain all required
* definitions and basic utilities functions to check grammar of a C file.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef LISTFILES
#define LISTFILES

#include <stdlib.h>
#include <stdio.h>
#include "../vendor/dirent.h"
#include <string.h>

int isNotExcluded(char **excludedFiles, char *file, int length);

void getFiles(char **files, int *pos, short isRecursive, char **excludedFiles,
              char *path, int length);

#endif
