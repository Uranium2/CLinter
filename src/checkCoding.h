#ifndef CHECKCODING
#define CHECKCODING
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "parser.h"

void checkmaxLineNumbers(int line, int nbChar, int maxLine);
void checkmaxFileLineNumbers(int nbLines, int linesConf);
void checkOperator(Token **listToken, int nbToken, int line);
void checkSpace(Token **listToken, int nbToken, int line);
void checkBracket(Token **listToken, int line);