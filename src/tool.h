#ifndef TOOL
#define TOOL

/**
* @file tool.h
* @brief This header file will contain all required
* definitions and basic utilities functions to print, check token's nature.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/

#include <stdlib.h>
#include <stdio.h>

#include "parser.h"

/**
 * @brief Exit the program with a display message
 * 
 * @param message The message displayed in STDOUT
 */
void exit_m(char *message);

/**
 * @brief The main printing function to print warning message with filename and position
 * 
 * @param message The message displayed on STDOUT
 * @param line  The line of the warning
 * @param pos  The position of the warning
 * @param fileName The file name location of the warning
 */
void print_warning(char *message, int line, int pos, char* fileName);

/**
 * @brief Tell if string is a C key word
 * 
 * @param str String to check
 * @return int 0 false else true
 */
int isKey(char *str);

/**
 * @brief Tell if a string is an Number
 * 
 * @param str String to check
 * @return int 0 false else true
 */
int isNum(char *str);

#endif
