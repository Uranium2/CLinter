#ifndef CHECKCODING
#define CHECKCODING

/**
* @file checkCoding.h
* @brief This header file will contain all required
* definitions and basic utilities functions to check rules on a C file.
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


void checkCommentsHeader(Token **listToken, int nbToken, int line, char *fileName, int *status, int lastLine);
void checkmaxLineNumbers(int line, int nbChar, int maxLine, char *fileName);
void checkmaxFileLineNumbers(int nbLines, int linesConf, char *fileName);
void checkOperator(Token **listToken, int nbToken, int line, char* fileName);
void checkSpace(Token **listToken, int nbToken, int line, char* fileName);
void checkBracket(Token **listToken, int line, char* fileName);

#endif
