/**
* @file checkVarFunc.h
* @brief This header file will contain all required
* definitions and basic utilities functions to check rules
* on functions or variables on a C file.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef CHECKVARFUN
#define CHECKVARFUN

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../parse/token.h"
#include "../parse/parser.h"

int skipSpaces(Token **listToken, int nbToken);

int containsStr(Token **listToken, int nbToken, char *str);

void multiDeclare(Token **listToken, int nbToken, int line, char *fileName, int *inComment);

#endif
