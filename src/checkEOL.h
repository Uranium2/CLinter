#ifndef CHECKEOL
#define CHECHECKEOLCKER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "parser.h"

void checkSpaceEOL(Token **listToken, int nbToken, int line);
void checkBracketEOL(Token **listToken, int nbToken, int line);

#endif