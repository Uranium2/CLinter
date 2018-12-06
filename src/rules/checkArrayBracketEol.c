/**
* @file checkArrayBracketEol.c
* @brief This c file will apply the checkArrayBracketEol rule.
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#include <memory.h>
#include "checkArrayBracketEol.h"
#include "../tools/tool.h"

/**
 * @brief Check the rule array-bracket-eol
 *
 * @param listToken List of Tokens
 * @param line Line in the file
 * @param fileName File name we are working on
 */
void checkBracket(Token **listToken, int line, char *fileName) {
    if (strcmp(listToken[0]->value, "{") == 0)
        print_warning("Bad bracket", line, 0, fileName);
}