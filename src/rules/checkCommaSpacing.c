/**
 * @file checkComma.c
 * @author Antoine TAVERNIER
 * @brief Function to determine if there is a missing space after a coma.
 * @version 0.1
 * @date 2018-12-07
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "checkCommaSpacing.h"

void checkCommaSpacing(Token **listToken, int nbToken, int line, char *fileName, int *inComment)
{
    if (*inComment == 1)
        return;
    
    
    for(int i = 0; i < nbToken; i++)
    {
        if (listToken[i]->type == COMA)
        {
            if (listToken[i]->value[0] == '\n')
                return;
            if (listToken[i + 1]->type != Delimiter && listToken[i]->value[0] != ' ')
                print_warning("Missing space after comma", line, listToken[i]->pos, fileName);
        }
    }
    
    
}