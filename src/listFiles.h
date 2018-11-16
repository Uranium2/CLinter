#ifndef LISTFILES
#define LISTFILES

/**
* @file listFiles.h
* @brief This header file will contain all required
* definitions and basic utilities functions to check grammar of a C file.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>


void getFiles(char **files, int *pos, short isRecursive, char **excludedFiles,
              char *path, int length);
#endif
