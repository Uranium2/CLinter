#ifndef CHECKCODING
#define CHECKCODING

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "parser.h"

void checkmaxLineNumbers(int line, int nbChar, int maxLine, char *fileName);
void checkmaxFileLineNumbers(int nbLines, int linesConf, char *fileName);
void checkOperator(Token **listToken, int nbToken, int line, char* fileName);
void checkSpace(Token **listToken, int nbToken, int line, char* fileName);
void checkBracket(Token **listToken, int line, char* fileName);

#endif
