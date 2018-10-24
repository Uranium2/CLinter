#include "token.h"

char* getEnumName(Type type) {
        
        switch (type)
        {
                case Operator:
                        return "Operator";
                        break;
                case KeyWord:
                        return "KeyWord";
                        break;
                case Delimiter:
                        return "Delimiter";
                        break;
                case Variable:
                        return "Variable";
                        break;
                case Numerical:
                        return "Numerical";
                        break;
                case Nothing:
                        return "Nothing";
                        break;
                default:
                        return "Nothing";
                        break;
        }
        return "Nothing";
}

Token *createToken(Type type, char *value)
{
        Token *token = malloc(sizeof(Token));
        token->type = type;
        token->value = value;
        return token;
}
