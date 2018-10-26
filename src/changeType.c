#include "changeType.h"

int isChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

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
            case ':':
            case ';':
            case '\'':
            case '"':
            case ' ':
            case '\t':
            case '{':
            case '}':
            case '[':
            case ']':
            case '|':
                listToken[i]->type = Delimiter;
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
        if (strcmp("const", listToken[i]->value) == 0)
            listToken[i]->type = CONST;
    }
}