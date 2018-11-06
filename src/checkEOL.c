#include "checkEOL.h"

void checkBracketEOL(Token **listToken, int line)
{
    if (strcmp(listToken[0]->value, "{") == 0)
        print_warning("Bad bracket", line, 0);
}

void checkSpaceEOL(Token **listToken, int nbToken, int line)
{
    for (int i = 0; i < nbToken; i++)
    {
        if (strcmp(listToken[i]->value, "\n") == 0 && strcmp(listToken[i - 1]->value, " ") == 0)
            print_warning("Extra space", line, i - 1);
    }
}