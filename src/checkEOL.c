#include "checkEOL.h"


void checkBracketEOL(Token **listToken, int nbToken, int line)
{
    if (strcmp(listToken[0]->value, "{") == 0)
        printf(YEL "Bad bracket position at " RED "%d" YEL " character " RED "%d \n" RESET, line, 0);

}

void checkSpaceEOL(Token **listToken, int nbToken, int line)
{  
    for(int i = 0; i < nbToken; i++)
    {
        if (strcmp(listToken[i]->value, "\n") == 0 && strcmp(listToken[i - 1]->value, " ") == 0)
            printf(YEL "Extra space at line " RED "%d" YEL " character " RED "%d \n" RESET, line, i -1);
    }
}