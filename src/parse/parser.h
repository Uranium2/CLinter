/**
* @file parser.h
* @brief This header file will contain all required
* definitions and basic utilities functions to transform text into Tokens.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef PARSER
#define PARSER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "../tools/tool.h"
#include "../parse/token.h"
#include "../rules/checker.h"
#include "../parse/changeType.h"

/**
 * @brief Color Macro for pretty printing in RED
 * 
 */
#define RED "\x1B[31m"
/**
 * @brief Color Macro for pretty printing in YELLOW
 * 
 */
#define YEL "\x1B[33m"
/**
 * @brief Reset to default color the printing color
 * 
 */
#define RESET "\x1B[0m"

Token **parse(char *str, int *nbNodes);

int isOpe(char c);

int isDelim(char c);

int isDelimNoSpace(char c);

char *getSubString(char *str, int left, int right);

#endif
