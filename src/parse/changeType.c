/**
* @file changeType.c
* @brief This c file will contain all functions to change type of a token.
* @author Antoine TAVERNIER
* @date 16/11/2018
*/
#include "changeType.h"

/**
 * @brief Assign Types for a list of Tokens
 * @param listToken List of Tokens
 * @param nbNodes Number of Tokens
 */
void assignTypes(Token **listToken, int nbNodes) {

    for (int i = 0; i < nbNodes; i++) {
        switch (listToken[i]->value[0]) {
            case '=':
                listToken[i]->type = EQ_OP;
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '&':
            case '^':
            case '>':
            case '<':
            case '!':
                listToken[i]->type = Operator;
                break;
            case ',':
                listToken[i]->type = COMA;
                break;
            case ';':
                listToken[i]->type = DotComa;
                break;
            case ':':
            case '\'':
            case '"':
            case ' ':
            case '\t':
            case '[':
            case ']':
            case '|':
                listToken[i]->type = Delimiter;
                break;
            case '{':
                listToken[i]->type = OpenBracket;
                break;
            case '}':
                listToken[i]->type = ClosedBracket;
                break;
            case ')':
                listToken[i]->type = ClosedPar;
                break;
            case '(':
                listToken[i]->type = OpenPar;
                break;
            default:
                listToken[i]->type = IDENTIFIER; // INDITENFIER
                break;
        }

        if (strcmp("int", listToken[i]->value) == 0)
            listToken[i]->type = KeyWord;
        if (strcmp("char", listToken[i]->value) == 0)
            listToken[i]->type = KeyWord;
        if (strcmp("void", listToken[i]->value) == 0)
            listToken[i]->type = KeyWord;
        if (strcmp("double", listToken[i]->value) == 0)
            listToken[i]->type = KeyWord;
        if (strcmp("float", listToken[i]->value) == 0)
            listToken[i]->type = KeyWord;
        if (strcmp("const", listToken[i]->value) == 0)
            listToken[i]->type = CONST;
        if (strcmp("return", listToken[i]->value) == 0)
            listToken[i]->type = RETURN;

        if (isNum(listToken[i]->value))
            listToken[i]->type = Numerical;
    }
}