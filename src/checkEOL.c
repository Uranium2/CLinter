#include "checkEOL.h"

void checkEOL(Token **listToken, int nbToken, int line)
{
    
    for(int i = 0; i < nbToken; i++)
    {
        printf("%s", listToken[i]->value);
        if (strcmp(listToken[i]->value, "\n") == 0 && strcmp(listToken[i - 1]->value, " ") == 0)
            printf(YEL "Extra space at end of line at line " RED "%d" YEL " character " RED "%d \n " RESET, line, i -1);
    }
}