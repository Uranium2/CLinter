//
// Created by theo on 03/12/18.
//

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