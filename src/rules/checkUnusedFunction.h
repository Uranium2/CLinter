/**
* @file checkUnusedFunction.h
* @brief Header file of checkUnusedFunction
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#ifndef CLINTER_CHECKUNUSEDFUNCTION_H
#define CLINTER_CHECKUNUSEDFUNCTION_H


#include "../tools/linterMemory.h"
#include "../parse/token.h"

void checkUnusedFunction(Token **listToken, int nbToken, int line, char *fileName, int *inComment, LinterMemory *lm);

#endif //CLINTER_CHECKUNUSEDFUNCTION_H
