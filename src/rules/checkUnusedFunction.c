/**
* @file checkUnusedFunction.c
* @brief This c file will apply the checkUnusedFunction rule.
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#include "checkUnusedFunction.h"


void checkUnusedFunction(Token **listToken, int nbToken, int line, char *fileName, int *inComment, LinterMemory *lm){
    //TODO : end function
    printf("nbToken : %d, line : %d, fileName : %s, inComment : %ls, listToken->value : %s", nbToken,line,fileName,inComment,listToken[0]->value);
    printLinterMemory(lm);
}