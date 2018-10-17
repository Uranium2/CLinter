#include "token.h"

Token* createToken(int type, char* value) {
        Token* token = malloc(sizeof(Token));
        token->type = type;
        token->value = value;
        return token;
}
