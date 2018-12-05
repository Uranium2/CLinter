//
// Created by theo on 03/12/18.
//

#include <memory.h>
#include "checkOperatorsSpacing.h"
#include "../tools/tool.h"

/**
 * @brief Check the rule operators-spacing
 *
 * @param listToken List of Tokens
 * @param nbToken number of Tokens
 * @param line Line in the file
 * @param fileName File name we are working on
 */
void checkOperator(Token **listToken, int nbToken, int line, char *fileName) {
    if (nbToken == 1)
        return;
    for (int i = 1; i < nbToken; i++) {
        if (listToken[i]->type == Operator && strcmp(listToken[i - 1]->value, " ") != 0 &&
            listToken[i - 1]->type != Operator && listToken[i - 1]->type != KeyWord)
            print_warning("Missing space", line, listToken[i]->pos, fileName);
        if ((listToken[i]->type == IDENTIFIER || listToken[i]->type == Numerical) && listToken[i - 1]->type == Operator)
            print_warning("Missing space", line, listToken[i]->pos, fileName);
        if (listToken[i]->type == EQ_OP && listToken[i - 1]->type == IDENTIFIER)
            print_warning("Missing space", line, listToken[i]->pos, fileName);
        if (listToken[i - 1]->type == EQ_OP && listToken[i]->type == IDENTIFIER)
            print_warning("Missing space", line, listToken[i]->pos, fileName);
    }
}