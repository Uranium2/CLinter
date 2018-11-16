#include "checkVarFunc.h"

/**
* @file checkVarFunc.c
* @brief This c file will contain all functions to check rules on functions or variables.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/

/**
 * @brief Skips the tokens with Delimiter Type
 * 
 * @param listToken List of Tokens
 * @param nbToken Number of Tokens
 * @return int 0 false else true
 */
int skipSpaces(Token **listToken, int nbToken)
{
    int i = 0;
    while (listToken[i]->type == Delimiter && i == nbToken - 1)
        i++;
    return i;
}

/**
 * @brief Check if the list of Tokens contains a specific strins
 * 
 * @param listToken List of Tokens
 * @param nbToken Numbers of Tokens
 * @param str String to check
 * @return int 0 false else true
 */
int containsStr(Token **listToken, int nbToken, char *str)
{
    for (int i = 0; i < nbToken; i++)
        if (strcmp(listToken[i]->value, str) == 0)
            return i;
    return 0;
}

/**
 * @brief Check the rule multi declaration
 * 
 * @param listToken List of Tokens
 * @param nbToken Number of Tokens
 * @param line At which line we are in the File
 * @param fileName The file name
 */
void multiDeclare(Token **listToken, int nbToken, int line, char* fileName)
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
        print_warning("Multiple declaration", line, listToken[posComma + 1]->pos, fileName);
}