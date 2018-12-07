/**
* @file checkUnusedVariable.c
* @brief This c file will apply the checkUnusedVariable rule.
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#include "checkUnusedVariable.h"
#include "../tools/tool.h"

void checkUnusedVariable(Token **listToken, int nbToken, int line, char *fileName, int *inComment, LinterMemory *lm)
{
    // TODO Finish method
    if (*inComment == 1)
        return;
    for (int i = 0; i < nbToken; i++)
    {
        if (listToken[i]->type == Variable && listToken[i + 1]->type == SPACE && listToken[i + 2]->type == STRING_LITERAL)
            lm->next = addElement(listToken[i]->value, line, i, fileName);
    }
}