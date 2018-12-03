//
// Created by Théo Huchard on 26/11/18.
//
#include "checkUnusedVariable.h"
#include "../tools/tool.h"

void checkUnusedVariable(Token **listToken, int nbToken, int line, char *fileName, int *inComment){

    print_warning("TEST", line, listToken[2 - 1]->pos, fileName);
}