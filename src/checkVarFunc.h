#ifndef CHECKVARFUN
#define CHECKVARFUN
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "parser.h"

void multiDeclare(Token **listToken, int nbToken, int line);