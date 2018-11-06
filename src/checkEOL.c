#include "checkEOL.h"

void checkmaxLineNumbers(int line, int nbChar, int maxLine)
{
    if (nbChar > maxLine)
        printf(RED "%d characters in line %d. Max is %d.\n" RESET, nbChar, line, maxLine);
}


void checkmaxFileLineNumbers(int nbLines, int linesConf)
{
    if (nbLines > linesConf)
        printf(RED "%d Lines in file. Max is %d.\n" RESET, nbLines, linesConf);
}

void checkOperatorEOL(Token **listToken, int nbToken, int line)
{
    if (nbToken == 1)
        return;
    for (int i = 0; i < nbToken; i++)
    {
        if (listToken[i]->type == Operator && strcmp(listToken[i - 1]->value, " ") != 0 &&
                listToken[i - 1]->type != Operator && listToken[i - 1]->type != KeyWord)
            print_warning("Missing space", line, listToken[i - 1]->pos);
        if ((listToken[i]->type == Variable || listToken[i]->type == Numerical) && listToken[i - 1]->type == Operator)
            print_warning("No space", line, listToken[i - 1]->pos);
    }
}

void checkBracketEOL(Token **listToken, int line)
{
    if (strcmp(listToken[0]->value, "{") == 0)
        print_warning("Bad bracket", line, 0);
}

void checkSpaceEOL(Token **listToken, int nbToken, int line)
{
    if (nbToken == 1)
        return;
    for (int i = 0; i < nbToken; i++)
    {
        if (strcmp(listToken[i]->value, "\n") == 0 && strcmp(listToken[i - 1]->value, " ") == 0)
            print_warning("Extra space", line, listToken[i - 1]->pos);
    }
}