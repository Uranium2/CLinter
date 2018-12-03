//
// Created by theo on 03/12/18.
//

#ifndef CLINTER_CHECKUNUSEDFUNCTION_H
#define CLINTER_CHECKUNUSEDFUNCTION_H


#include "../tools/linterMemory.h"
#include "../parse/token.h"

void checkUnusedFunction(Token **listToken, int nbToken, int line, char *fileName, int *inComment, LinterMemory *lm);

#endif //CLINTER_CHECKUNUSEDFUNCTION_H
