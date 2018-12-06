/**
* @file checkCommentsHeader.h
* @brief Header file of checkCommentsHeader
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#ifndef CLINTER_CHECKCOMMENTSHEADER_H
#define CLINTER_CHECKCOMMENTSHEADER_H

#include "../parse/token.h"

void checkCommentsHeader(Token **listToken, int nbToken, int line, char *fileName, int *status, int lastLine);

#endif //CLINTER_CHECKCOMMENTSHEADER_H
