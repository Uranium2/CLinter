#ifndef CHECKEOL
#define CHECHECKEOLCKER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "parser.h"

void checkmaxFileLineNumbers(int nbLines, int linesConf);
void checkOperatorEOL(Token **listToken, int nbToken, int line);
void checkSpaceEOL(Token **listToken, int nbToken, int line);
void checkBracketEOL(Token **listToken, int line);

#endif
