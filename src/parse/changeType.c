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
void assignTypes(Token **listToken, int nbNodes)
{

    for (int i = 0; i < nbNodes; i++)
    {
        if (listToken[i]->type == Comment)
            continue;
        if ((listToken[i]->value[0] == '+' && listToken[i + 1]->value[0] == '+') ||
            (listToken[i]->value[0] == '+' && listToken[i + 1]->value[0] == '+'))
        {
            listToken[i]->type = INC_OP;
            listToken[i + 1]->type = INC_OP;
            i++;
            continue;
        }
        if ((listToken[i]->value[0] == '+' && listToken[i + 1]->value[0] == '+') ||
            (listToken[i]->value[0] == '<' && listToken[i + 1]->value[0] == '=') ||
            (listToken[i]->value[0] == '>' && listToken[i + 1]->value[0] == '=') ||
            (listToken[i]->value[0] == '!' && listToken[i + 1]->value[0] == '=') ||
            (listToken[i]->value[0] == '-' && listToken[i + 1]->value[0] == '>') ||
            (listToken[i]->value[0] == '&' && listToken[i + 1]->value[0] == '&') ||
            (listToken[i]->value[0] == '|' && listToken[i + 1]->value[0] == '|'))
                {
            listToken[i]->type = INC_OP;
            listToken[i + 1]->type = INC_OP;
            i++;
            continue;
        }
        switch (listToken[i]->value[0])
        {
        case '=':
            listToken[i]->type = EQ_OP;
            break;
        case '+':
        case '-':
        case '/':
        case '%':
        case '&':
        case '^':
        case '>':
        case '<':
        case '!':
            listToken[i]->type = Operator;
            break;
        case '*':
            listToken[i]->type = MUL_ASSIGN;
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
        case '\n':
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
        if (listToken[i]->value[0] == '/' && listToken[i]->value[1] == '*')
            listToken[i]->type = Comment;
        if (listToken[i]->value[0] == '/' && listToken[i]->value[1] == '/')
            listToken[i]->type = Comment;
        if (strcmp("if", listToken[i]->value) == 0)
            listToken[i]->type = IF;
        if (strcmp("else", listToken[i]->value) == 0)
            listToken[i]->type = ELSE;
        if (strcmp("while", listToken[i]->value) == 0)
            listToken[i]->type = WHILE;
        if (strcmp("case", listToken[i]->value) == 0)
            listToken[i]->type = CASE;
        if (strcmp("break", listToken[i]->value) == 0)
            listToken[i]->type = BREAK;
        if (strcmp("continue", listToken[i]->value) == 0)
            listToken[i]->type = CONTINUE;
        if (strcmp("for", listToken[i]->value) == 0)
            listToken[i]->type = FOR;
        if (strcmp("switch", listToken[i]->value) == 0)
            listToken[i]->type = SWITCH;
        if (strcmp("int", listToken[i]->value) == 0)
            listToken[i]->type = INT;
        if (strcmp("long", listToken[i]->value) == 0)
            listToken[i]->type = LONG;
        if (strcmp("char", listToken[i]->value) == 0)
            listToken[i]->type = CHAR;
        if (strcmp("void", listToken[i]->value) == 0)
            listToken[i]->type = VOID;
        if (strcmp("double", listToken[i]->value) == 0)
            listToken[i]->type = DOUBLE;
        if (strcmp("float", listToken[i]->value) == 0)
            listToken[i]->type = FLOAT;
        if (strcmp("const", listToken[i]->value) == 0)
            listToken[i]->type = Delimiter;
        if (strcmp("unsigned", listToken[i]->value) == 0)
            listToken[i]->type = UNSIGNED;
        if (strcmp("signed", listToken[i]->value) == 0)
            listToken[i]->type = SIGNED;
        if (strcmp("return", listToken[i]->value) == 0)
            listToken[i]->type = RETURN;

        if (isNum(listToken[i]->value))
            listToken[i]->type = Numerical;
    }
}