//
// Created by Théo Huchard on 26/11/18.
//
#include "checkUnusedVariable.h"
#include "../tools/tool.h"

void checkUnusedVariable(Token **listToken, int nbToken, int line, char *fileName, int *inComment, LinterMemory *lm){
    // TODO Finish method
    if (*inComment == 1)
        return;
    for(int i = 0; i < nbToken; i++){
        if(listToken[i]->type == Variable && listToken[i+1]->type == SPACE && listToken[i+2]->type == STRING_LITERAL)
            lm->next = addElement(listToken[i]->value,line,i,fileName);
    }
}