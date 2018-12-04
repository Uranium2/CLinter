//
// Created by theo on 03/12/18.
//

#ifndef CLINTER_CHECKCOMMENTSHEADER_H
#define CLINTER_CHECKCOMMENTSHEADER_H

#include "../parse/token.h"

void checkCommentsHeader(Token **listToken, int nbToken, int line, char *fileName, int *status, int lastLine);

#endif //CLINTER_CHECKCOMMENTSHEADER_H
