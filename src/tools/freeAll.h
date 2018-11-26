/**
* @file freeAll.h
* @brief This header file will contain all required
* definitions and basic utilities functions to free the memory of the program.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef FREEALL
#define FREEALL

#include <stdlib.h>
#include <stdio.h>

#include "../config/config.h"
#include "../parse/token.h"

void clean_text(char **codeText, int nbLines);

void free_conf(Config *conf);

void free_text(char **codeText, int nbLines);

void free_tokenList(Token **tokenList, int nbNodes);

void free_files(char **files, int nbFiles);

#endif
