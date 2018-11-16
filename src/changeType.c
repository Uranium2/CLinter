#include "changeType.h"

void assignTypes(Token **listToken, int nbNodes)
{

    for (int i = 0; i < nbNodes; i++)
    {
        switch (listToken[i]->value[0])
        {
        case '=':
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
            listToken[i]->type = INT;
        if (strcmp("char", listToken[i]->value) == 0)
            listToken[i]->type = CHAR;
        if (strcmp("void", listToken[i]->value) == 0)
            listToken[i]->type = VOID;
        if (strcmp("double", listToken[i]->value) == 0)
            listToken[i]->type = DOUBLE;
        if (strcmp("float", listToken[i]->value) == 0)
            listToken[i]->type = FLOAT;
        if (strcmp("const", listToken[i]->value) == 0)
            listToken[i]->type = CONST;
        if (strcmp("return", listToken[i]->value) == 0)
            listToken[i]->type = RETURN;

        if (isNum(listToken[i]->value))
            listToken[i]->type = Numerical;
    }
}