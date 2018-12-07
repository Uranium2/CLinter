/**
 * @file checkComma.h
 * @author Antoine TAVERNIER
 * @brief Function to determine if there is a missing space after a coma.
 * @version 0.1
 * @date 2018-12-07
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <string.h>
#include "../parse/token.h"
#include "../tools/tool.h"

void checkCommaSpacing(Token **listToken, int nbToken, int line, char *fileName, int *inComment);
