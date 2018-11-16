#ifndef PARSER
#define PARSER

/**
* @file parser.h
* @brief This header file will contain all required
* definitions and basic utilities functions to transform text into Tokens.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "tool.h"
#include "token.h"
#include "checker.h"
#include "changeType.h"

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

/**
 * @brief Reads a string and prints each token type
 * 
 * @param str input string (code from given file)
 * @param nbNodes number of nodes in string
 * @return Token** list of list of tokens
 */
Token **parse(char *str, int *nbNodes);

/**
 * @brief Tell if char is an operator
 * 
 * @param c character to check
 * @return int 0 false else true
 */
int isOpe(char c);

/**
 * @brief Tell if char is a delimiter + operator
 * 
 * @param c character to check
 * @return int 0 false else true
 */
int isDelim(char c);


/**
 * @brief Tell if char is a delimiter expect space ' '
 * 
 * @param c character to check
 * @return int 0 false else true
 */
int isDelimNoSpace(char c);

/**
 * @brief Get subString of str delimited by left and right
 * 
 * @param c character to check
 * @return int 0 false else true
 */
char *getSubString(char *str, int left, int right);

#endif
