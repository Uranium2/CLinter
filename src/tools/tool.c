/**
* @file tool.c
* @brief This c file will contain all functions for various tools.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#include "tool.h"

/**
 * @brief Exit the program with a display message
 * 
 * @param message The message displayed in STDOUT
 */
void exit_m(char *message) {
    printf("FORCE EXIT BECAUSE \"%s\" FAILED\n", message);
    exit(1);
}

/**
 * @brief The main printing function to print warning message with filename and position
 * 
 * @param message The message displayed on STDOUT
 * @param line  The line of the warning
 * @param pos  The position of the warning
 * @param fileName The file name location of the warning
 */
void print_warning(char *message, int line, int pos, char *fileName) {
    //if (fileName == NULL)
    //	printf("FileName is NULL %s", fileName);
    printf(YEL "%s at line " RED "%d" YEL " character for " RED "%d " YEL "for file " RED "%s\n" RESET, message, line,
           pos, fileName);
}

/**
 * @brief Tell if string is a C key word
 * 
 * @param str String to check
 * @return int 0 false else true
 */
int isKey(char *str) {
    return (!strcmp(str, "int") || !strcmp(str, "float") ||
            !strcmp(str, "double") || !strcmp(str, "char") ||
            !strcmp(str, "if") || !strcmp(str, "else") ||
            !strcmp(str, "while") || !strcmp(str, "do") ||
            !strcmp(str, "for") || !strcmp(str, "unsigned") ||
            !strcmp(str, "break") || !strcmp(str, "continue") ||
            !strcmp(str, "switch") || !strcmp(str, "return") ||
            !strcmp(str, "case") || !strcmp(str, "short") ||
            !strcmp(str, "static") || !strcmp(str, "void") ||
            !strcmp(str, "struct"));
}

/**
 * @brief Tell if a string is an Number
 * 
 * @param str String to check
 * @return int 0 false else true
 */
int isNum(char *str) {
    if (str == NULL)
        exit_m("isNum: str == NULL");
    int len = strlen(str);
    if (len <= 0)
        return 0;
    char *end;
    strtod(str, &end);
    if (end == str)
        return 0;
    if (strlen(end) > 0)
        return 0;
    return 1;
}