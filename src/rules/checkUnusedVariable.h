//
// Created by Théo Huchard on 26/11/18.
//

#ifndef CLINTER_CHECKUNUSEDVARIABLE_H
#define CLINTER_CHECKUNUSEDVARIABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../parse/token.h"
#include "../tools/linterMemory.h"

void checkUnusedVariable(Token **listToken, int nbToken, int line, char *fileName, int *inComment, LinterMemory *lm);

#endif //CLINTER_CHECKUNUSEDVARIABLE_H
