/**
* @file checkOperatorsSpacing.h
* @brief Header file of checkOperatorsSpacing
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#ifndef CLINTER_CHECKOPERATORSSPACING_H
#define CLINTER_CHECKOPERATORSSPACING_H

#include "../parse/token.h"

void checkOperator(Token **listToken, int nbToken, int line, char *fileName);

#endif //CLINTER_CHECKOPERATORSSPACING_H
