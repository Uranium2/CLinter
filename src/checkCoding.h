#ifndef CHECKCODING
#define CHECKCODING

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "parser.h"

void checkmaxLineNumbers(int line, int nbChar, int maxLine);
void checkmaxFileLineNumbers(int nbLines, int linesConf);
void checkOperatorEOL(Token **listToken, int nbToken, int line);
void checkSpaceEOL(Token **listToken, int nbToken, int line);
void checkBracketEOL(Token **listToken, int line);

#endif
