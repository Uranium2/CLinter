//
// Created by theo on 03/12/18.
//

#include <memory.h>
#include "checkNoTrailingSpaces.h"
#include "../tools/tool.h"

/**
 * @brief Check the rule no-trailing-spaces
 *
 * @param listToken List of Tokens
 * @param nbToken number of Tokens
 * @param line Line in the file
 * @param fileName File name we are working on
 */
void checkSpace(Token **listToken, int nbToken, int line, char *fileName) {
    if (nbToken == 1)
        return;
    for (int i = 0; i < nbToken; i++) {
        if (strcmp(listToken[i]->value, "\n") == 0 && strcmp(listToken[i - 1]->value, " ") == 0)
            print_warning("Extra space", line, listToken[i]->pos, fileName);
    }
}