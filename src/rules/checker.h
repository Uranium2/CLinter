/**
* @file checker.h
* @brief This header file will contain all required
* definitions and basic utilities functions to check grammar of a C file.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef CHECKER
#define CHECKER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../parse/token.h"
#include "../parse/parser.h"
#include "../tools/stack.h"

void check(Token **listToken, int nbToken, Stack *stack, Collector *c);

int containsStr(Token **listToken, int nbToken, char *str);

#endif
