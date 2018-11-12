#include "checkCoding.h"

void checkmaxLineNumbers(int line, int nbChar, int maxLine, char *fileName)
{
    if (nbChar > maxLine)
        printf(RED "%d characters in line %d for file %s. Max is %d.\n" RESET, nbChar, line, fileName, maxLine);
}

void checkmaxFileLineNumbers(int nbLines, int linesConf, char *filName)
{
    if (nbLines > linesConf)
        printf(RED "%d Lines in file for file %s. Max is %d.\n" RESET, nbLines, filName, linesConf);
}

void checkOperator(Token **listToken, int nbToken, int line, char *fileName)
{
    if (nbToken == 1)
        return;
    for (int i = 1; i < nbToken; i++)
    {
        if (listToken[i]->type == Operator && strcmp(listToken[i - 1]->value, " ") != 0 &&
            listToken[i - 1]->type != Operator && listToken[i - 1]->type != KeyWord)
            print_warning("Missing space", line, listToken[i - 1]->pos, fileName);
        if ((listToken[i]->type == Variable || listToken[i]->type == Numerical) && listToken[i - 1]->type == Operator)
            print_warning("No space", line, listToken[i - 1]->pos, fileName);
    }
}

void checkBracket(Token **listToken, int line, char *fileName)
{
    if (strcmp(listToken[0]->value, "{") == 0)
        print_warning("Bad bracket", line, 0, fileName);
}

void checkSpace(Token **listToken, int nbToken, int line, char *fileName)
{
    if (nbToken == 1)
        return;
    for (int i = 0; i < nbToken; i++)
    {
        if (strcmp(listToken[i]->value, "\n") == 0 && strcmp(listToken[i - 1]->value, " ") == 0)
            print_warning("Extra space", line, listToken[i - 1]->pos, fileName);
    }
}