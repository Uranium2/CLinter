#include <string.h>

#include "../parse/token.h"

typedef 
struct ItemName_T
{
    char* name;
    short isDeclaration;
    short isCall;
    Type type;
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