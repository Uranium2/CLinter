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
void exit_m(char *message)
{
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
void print_warning(char *message, int line, int pos, char *fileName)
{
    printf(YEL "%s at line " RED "%d" YEL " character for " RED "%d " YEL "for file " RED "%s\n" RESET, message, line,
           pos, fileName);
}

/**
 * @brief Tell if string is a C key word
 * 
 * @param str String to check
 * @return int 0 false else true
 */
int isKey(char *str)
{
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
int isNum(char *str)
{
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

void change_color(Token *tok)
{

    switch (tok->type)
    {
    case IF:
    case ELSE:
    case SWITCH:
    case FOR:
    case CASE:
    case CONTINUE:
    case BREAK:
    case DEFAULT:
    case RETURN:
        printf(CYN);
        break;
    case Numerical:
        printf(CYN);
        break;
    case INT:
    case FLOAT:
    case CONST:
    case DOUBLE:
    case CHAR:
    case UNSIGNED:
    case STRUCT:
    case UNION:
    case SIGNED:
    case SIZEOF:
    case VOID:
    case LONG:
    case SHORT:
        printf(BLU);
        break;
    case Comment:
        printf(GRN);
        break;
    case IDENTIFIER:
        printf(YEL);
        break;
    default:
        printf(RESET);
        break;
    }
}

/**
 * @brief Main printing function. It will print the a line of code given in a list of tokens.
 * 
 * @param nbNodes Number of nodes in the tokenList.
 * @param tokenList List of Tokens.
 * @param debug 0 normal printing. Else debug printing. Display types next to the token.
 */
void print_line(int nbNodes, Token **tokenList, int debug)
{
    if (!debug)
    {
        for (int j = 0; j < nbNodes; j++)
        {
            change_color(tokenList[j]);
            printf("%s", tokenList[j]->value);
        }
    }
    else
    {
        for (int j = 0; j < nbNodes; j++)
            printf("%s '%s'", tokenList[j]->value, getEnumName(tokenList[j]->type));
    }
}