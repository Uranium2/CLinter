//
// Created by Théo Huchard on 26/11/18.
//
#include "checkUnusedFunction.h"


void checkUnusedFunction(Token **listToken, int nbToken, int line, char *fileName, int *inComment, LinterMemory *lm){
    //TODO : end function
    printf("nbToken : %d, line : %d, fileName : %s, inComment : %ls, listToken->value : %s", nbToken,line,fileName,inComment,listToken[0]->value);
    printLinterMemory(lm);
}