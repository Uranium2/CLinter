#include <string.h>

#include "../parse/token.h"

/**
 * @brief This structure is the call stack. It's purpuse is to check if one variable can be used in a scope.
 * 
 */
typedef struct Stack_t
{
    Token** tokens;
    int top;
    int size;
} Stack;

Stack *stackInit();
void stackPush(Stack *st, Token *tok);