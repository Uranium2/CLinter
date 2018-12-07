/**
* @file tool.h
* @brief This header file will contain all required
* definitions and basic utilities functions to print, check token's nature.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef TOOL
#define TOOL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../parse/token.h"

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
 * @brief Color Macro for pretty printing in BLUE
 *
 */
#define BLU "\x1B[34m"
/**
 * @brief Color Macro for pretty printing in MAGENTA
 *
 */
#define MAG "\x1B[35m"
/**
 * @brief Color Macro for pretty printing in CYANT
 *
 */
#define CYN "\x1B[36m"
/**
 * @brief Color Macro for pretty printing in GREEN
 *
 */
#define GRN "\x1B[32m"
/**
 * @brief Reset to default color the printing color
 *
 */
#define RESET "\x1B[0m"

void exit_m(char *message);

void print_warning(char *message, int line, int pos, char *fileName);

int isKey(char *str);

int isNum(char *str);

void print_line(int nbNodes, Token **tokenList, int debug);

#endif
