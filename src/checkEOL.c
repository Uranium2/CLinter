#include "checkEOL.h"

void checkOperatorEOL(Token **listToken, int nbToken, int line)
{
    for (int i = 0; i < nbToken; i++)
    {
        if (listToken[i]->type == Operator && strcmp(listToken[i - 1]->value, " ") != 0 &&
                listToken[i - 1]->type != Operator && listToken[i - 1]->type != KeyWord)
            print_warning("Missing space", line, i - 1);
        if (listToken[i]->type == Numerical && listToken[i - 1]->type == Operator)
            print_warning("No space", line, i - 1);
    }
}

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