/**
* @file checkNoMultiDeclaration.h
* @brief Header file of checkNoMultiDeclaration
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#ifndef CLINTER_CHECKNOMULTIDECLARATION_H
#define CLINTER_CHECKNOMULTIDECLARATION_H

#include "../parse/token.h"

void multiDeclare(Token **listToken, int nbToken, int line, char *fileName, int *inComment);

#endif //CLINTER_CHECKNOMULTIDECLARATION_H
