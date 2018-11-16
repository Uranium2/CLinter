#ifndef CHECKVARFUN
#define CHECKVARFUN

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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "parser.h"

void multiDeclare(Token **listToken, int nbToken, int line, char* fileName);

#endif
