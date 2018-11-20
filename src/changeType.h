/**
* @file changeType.h
* @brief This header file will contain all required
* definitions and basic utilities functions to change type of a token.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef CHANGETYPE
#define CHANGETYPE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "parser.h"

/**
 * @brief Assign new types to tokens
 * 
 * @param listToken 
 * @param nbNodes 
 */
void assignTypes(Token **listToken, int nbNodes);

#endif
