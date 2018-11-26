/**
* @file checkCoding.c
* @brief This c file will contain all functions to check simple coding style rules.
* @author Antoine TAVERNIER
* @date 16/11/2018
*/
#include "checkCoding.h"

/**
 * @brief Check the rule comments-header
 * @param listToken List of Tokens
 * @param nbToken number of Tokens
 * @param line Line in the file
 * @param status State of comment header. 0 no comment. 1 Only opening Comment. 2 closed Comment
 * @param lastLine Helps to trigger the warning message at end of file
 * @param fileName File name we are working on
 */
void checkCommentsHeader(Token **listToken, int nbToken, int line, char *fileName, int *status, int lastLine) {
    if (line - 1 == lastLine && *status < 2) {
        print_warning("Missing header", 0, 0, fileName);
        return;
    }
    if (line > 5 || *status > 1)
        return;
    for (int i = 0; i < nbToken - 1; i++) {
        if (*status == 0 && strcmp(listToken[i]->value, "/") == 0 && strcmp(listToken[i + 1]->value, "*") == 0)
            *status = *status + 1;
        else if (*status == 1 && strcmp(listToken[i]->value, "*") == 0 && strcmp(listToken[i + 1]->value, "/") == 0)
            *status = *status + 1;
    }
}

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
 * @brief 
 * 
 * @param nbLines Number of lines in the file
 * @param linesConf Number max of lines in a file from configuration
 * @param filName File name we are working on
 */
void checkmaxFileLineNumbers(int nbLines, int linesConf, char *filName) {
    if (nbLines > linesConf)
        printf(RED "%d Lines in file for file %s. Max is %d.\n" RESET, nbLines - 1, filName, linesConf);
}

/**
 * @brief Check the rule operators-spacing
 * 
 * @param listToken List of Tokens
 * @param nbToken number of Tokens
 * @param line Line in the file
 * @param fileName File name we are working on
 */
void checkOperator(Token **listToken, int nbToken, int line, char *fileName) {
    if (nbToken == 1)
        return;
    for (int i = 1; i < nbToken; i++) {
        if (listToken[i]->type == Operator && strcmp(listToken[i - 1]->value, " ") != 0 &&
            listToken[i - 1]->type != Operator && listToken[i - 1]->type != KeyWord)
            print_warning("Missing space", line, listToken[i - 1]->pos, fileName);
        if ((listToken[i]->type == Variable || listToken[i]->type == Numerical) && listToken[i - 1]->type == Operator)
            print_warning("No space", line, listToken[i - 1]->pos, fileName);
    }
}

/**
 * @brief Check the rule array-bracket-eol
 * 
 * @param listToken List of Tokens
 * @param line Line in the file
 * @param fileName File name we are working on
 */
void checkBracket(Token **listToken, int line, char *fileName) {
    if (strcmp(listToken[0]->value, "{") == 0)
        print_warning("Bad bracket", line, 0, fileName);
}

/**
 * @brief Check the rule no-trailing-spaces
 * 
 * @param listToken List of Tokens
 * @param nbToken number of Tokens
 * @param line Line in the file
 * @param fileName File name we are working on
 */
void checkSpace(Token **listToken, int nbToken, int line, char *fileName) {
    if (nbToken == 1)
        return;
    for (int i = 0; i < nbToken; i++) {
        if (strcmp(listToken[i]->value, "\n") == 0 && strcmp(listToken[i - 1]->value, " ") == 0)
            print_warning("Extra space", line, listToken[i - 1]->pos, fileName);
    }
}