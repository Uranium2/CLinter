/**
* @file tool.h
* @brief This header file will contain all required
* definitions and basic utilities functions to print, check token's nature.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef TOOL
#define TOOL

#include <stdlib.h>
#include <stdio.h>

#include "../parse/parser.h"

void exit_m(char *message);

void print_warning(char *message, int line, int pos, char *fileName);

int isKey(char *str);

int isNum(char *str);

#endif
