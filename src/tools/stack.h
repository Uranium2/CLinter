#include <string.h>

#include "../parse/token.h"
#include "tool.h"
#include "collector.h"

/**
 * @brief This strcuture can tell if a Identifier is a variable, function, call or declaration
 * 
 */
typedef struct ItemName_T
{
    char *name;          /**< name of the Identifier. */
    short isDeclaration; /**< Is a Declaration 1 else 0. */
    short isCall;        /**< Is a Call 1 else 0. */
    short isVar;         /**< Is a Variable 1 else is a Function 0. */
    char *type;          /**< Type of the Identifier */
    int line;            /**< Position of the Identifier in the file */
} ItemName;

/**
 * @brief This structure is a stack. It's purpuse is to check if variable/function are declared or unused in a scope.
 * 
 */
typedef struct Stack_t
{
    ItemName **itemNames; /**< List of items. */
    int *top;             /**< List of top position for scopes. */
    int size;             /**< Size of itemNames. */
    int *base;            /**< List of base position for scopes. */
    int posTopBase;       /**< Position in the base and top list. */
} Stack;

Stack *stackInit(Collector *c);
void stackPush(Stack *st, Token *tok, int isDeclaration, int isCall, int varOrFunc, char *type, Collector *c);
void stackPrint(Stack *st);
void checkUnusedVar(Stack *st, char *file);
void checkUnusedFunc(Stack *st, char *file);
void checkUndeclaredVar(Stack *st, char *file);
void checkUndeclaredFunc(Stack *st, char *file);
void stackAddScope(Stack *st);
void stackRemoveScope(Stack *st);