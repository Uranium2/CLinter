#include <string.h>

#include "../parse/token.h"
#include "tool.h"
#include "collector.h"

typedef 
struct ItemName_T
{
    char* name;
    short isDeclaration;
    short isCall;
    short isVar;
    char* type;
    int line;
} ItemName;


/**
 * @brief This structure is the call stack. It's purpuse is to check if one variable can be used in a scope.
 * 
 */
typedef struct Stack_t
{
    ItemName** itemNames;
    int *top;
    int size;
    int *base;
    int posTopBase;
} Stack;

Stack *stackInit(Collector *c);
void stackPush(Stack *st, Token *tok, int isDeclaration, int isCall, int varOrFunc, char *type, Collector *c);
void stackPrint(Stack *st);
void checkUnusedVar(Stack *st, char* file);
void checkUnusedFunc(Stack *st, char* file);
void checkUndeclaredVar(Stack *st, char* file);
void checkUndeclaredFunc(Stack *st, char *file);
void stackAddScope(Stack *st);
void stackRemoveScope(Stack *st);