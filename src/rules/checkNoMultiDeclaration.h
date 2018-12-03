//
// Created by theo on 03/12/18.
//

#ifndef CLINTER_CHECKNOMULTIDECLARATION_H
#define CLINTER_CHECKNOMULTIDECLARATION_H

#include "../parse/token.h"

void multiDeclare(Token **listToken, int nbToken, int line, char *fileName, int *inComment);

#endif //CLINTER_CHECKNOMULTIDECLARATION_H
