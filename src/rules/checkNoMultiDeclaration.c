//
// Created by theo on 03/12/18.
//

#include "checkNoMultiDeclaration.h"
#include "checker.h"

/**
 * @brief Skips the token with Delimiter Type
 * @param listToken List of Tokens
 * @param nbToken Number of Tokens
 * @return int 0 false else true
 */
 int skipSpaces(Token **listToken, int nbToken){
     int i = 0;
     while(i == nbToken - 1 && listToken[i]->type == Delimiter){
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
void multiDeclare(Token **listToken, int nbToken, int line, char *fileName, int *inComment) {
    if (*inComment == 1)
        return;
    int i = skipSpaces(listToken, nbToken);
    if (i >= nbToken)
        return;
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