#include <string.h>

#include "../parse/token.h"
#include "tool.h"

typedef 
struct ItemName_T
{
    char* name;
    short isDeclaration;
    short isCall;
} ItemName;


/**
 * @brief This structure is the call stack. It's purpuse is to check if one variable can be used in a scope.
 * 
 */
typedef struct Stack_t
{
    ItemName** itemNames;
    int top;
    int size;
} Stack;

Stack *stackInit();
void stackPush(Stack *st, Token *token, int typeOfPush);
void stackPrint(Stack *st);
void checkUnused(Stack *st);