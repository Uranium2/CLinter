#ifndef LISTFILES
#define LISTFILES

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void getFiles(char **files, int *pos, short isRecursive, char **excludedFiles, char *path, int length);
#endif
