/**
* @file checkNoMultiDeclaration.c
* @brief This c file will apply the checkNoMultiDeclaration rule.
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#include "checkNoMultiDeclaration.h"
#include "checker.h"

/**
 * @brief Skips the token with Delimiter Type
 * @param listToken List of Tokens
 * @param nbToken Number of Tokens
 * @return int 0 false else true
 */
int skipSpaces(Token **listToken, int nbToken)
{
    int i = 0;
    while (i == nbToken - 1 && listToken[i]->type == Delimiter)
    {
        i++;
    }
    return i;
}

/**
 * @brief Check the rule multi declaration
 *
 * @param listToken List of Tokens
 * @param nbToken Number of Tokens
 * @param line At which line we are in the File
 * @param fileName The file name
 */
void multiDeclare(Token **listToken, int nbToken, int line, char *fileName, int *inComment)
{
    if (*inComment == 1)
        return;
    int i = skipSpaces(listToken, nbToken);
    if (i >= nbToken)
        return;
    if (!(listToken[i]->type == INT || listToken[i]->type == CHAR ||
          listToken[i]->type == LONG || listToken[i]->type == SHORT ||
          listToken[i]->type == FLOAT || listToken[i]->type == DOUBLE ||
          listToken[i]->type == SIGNED || listToken[i]->type == UNSIGNED ||
          listToken[i]->type == CONST || listToken[i]->type == VOID))
        return;
    if (containsStr(listToken, nbToken, "{"))
        return;
    if (!containsStr(listToken, nbToken, ";"))
        return;
    int posComma = containsStr(listToken, nbToken, ",");
    if (posComma)
        print_warning("Multiple declaration", line, listToken[posComma + 1]->pos, fileName);
}