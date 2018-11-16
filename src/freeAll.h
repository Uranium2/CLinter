#ifndef FREEALL
#define FREEALL

/**
* @file freeAll.h
* @brief This header file will contain all required
* definitions and basic utilities functions to free the memory of the program.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/

#include <stdlib.h>
#include <stdio.h>

#include "config.h"

void clean_text(char **codeText, int nbLines);
void free_conf(Config* conf);
void free_text(char** codeText, int nbLines);
void free_tokenList(Token **tokenList, int nbNodes);
void free_files(char** files, int nbFiles);
#endif
