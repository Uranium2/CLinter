/**
* @file checkNoTrailingSpaces.h
* @brief Header file of checkNoTrailingSpaces
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#ifndef CLINTER_CHECKNOTRALLINGSPACES_H
#define CLINTER_CHECKNOTRALLINGSPACES_H

#include "../parse/token.h"

void checkSpace(Token **listToken, int nbToken, int line, char *fileName);

#endif //CLINTER_CHECKNOTRALLINGSPACES_H
