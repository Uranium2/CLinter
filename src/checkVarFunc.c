#include "checkVarFunc.h"

int skipSpaces(Token **listToken, int nbToken)
{
    int i = 0;
    while (listToken[i]->type == Delimiter && i == nbToken - 1)
        i++;
    return i;
}

int containsStr(Token **listToken, int nbToken, char *str)
{
    for (int i = 0; i < nbToken; i++)
        if (strcmp(listToken[i]->value, str) == 0)
            return i;
    return 0;
}

void multiDeclare(Token **listToken, int nbToken, int line)
{
    int i = skipSpaces(listToken, nbToken);
    if (!(listToken[i]->type == KeyWord))
        return;
    if (containsStr(listToken, nbToken, "{"))
        return;
    if (!containsStr(listToken, nbToken, ";"))
        return;
    int posComma = containsStr(listToken, nbToken, ",");
    if (posComma)
        print_warning("Multiple declaration", line, listToken[posComma + 1]->pos);
}