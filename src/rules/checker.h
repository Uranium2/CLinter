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


void check(Token **listToken, int nbToken);

#endif
