/**
* @file checkMaxLineNumbers.c
* @brief This c file will apply the checkMaxLineNumbers rule.
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#include <stdio.h>
#include "checkMaxLineNumbers.h"
#include "../tools/tool.h"

/**
 * @brief max-line-numbers
 *
 * @param line Line in the file
 * @param nbChar Number of character in the line
 * @param maxLine Number max of character in the line
 * @param fileName File name we are working on
 */
void checkMaxLineNumbers(int line, int nbChar, int maxLine, char *fileName) {
    if (nbChar > maxLine)
        printf(RED "%d characters in line %d for file %s. Max is %d.\n" RESET, nbChar, line, fileName, maxLine);
}

/**
 * @brief max-file-line-numbers
 *
 * @param nbLines Number of lines in the file
 * @param linesConf Number max of lines in a file from configuration
 * @param filName File name we are working on
 */
void checkmaxFileLineNumbers(int nbLines, int linesConf, char *filName) {
    if (nbLines > linesConf)
        printf(RED "%d Lines in file for file %s. Max is %d.\n" RESET, nbLines - 1, filName, linesConf);
}