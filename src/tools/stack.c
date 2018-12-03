#include "stack.h"

/**
 * @brief Check if a variable is declared in the scope
 * 
 * @param st Stack of variables
 * @return int 0 not empty else empty
 * @return int 
 */
int isInScope(Stack *st, Token token)
{
    return 0;
}

/**
 * @brief Create a new empty call Stack
 * 
 * @return Stack* Pointer to an empty call stack
 */
Stack *stackInit()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->size = 100;
    stack->itemNames = malloc(sizeof(ItemName *) * stack->size);
    stack->top = 0;
    return stack;
}

/**
 * @brief Push a new variable at the top of the Stack
 * 
 * @param st Stack of variables
 * @param tok Variable to push
 */
void stackPush(Stack *st, Token *tok, int typeOfPush)
{
    // check if stack is full
    ItemName *it = malloc(sizeof(ItemName));
    it->type = tok->type;
    it->name = tok->value;
    if (typeOfPush == 1)
    {
        it->isDeclaration = 1;
        it->isCall = 0;
    }
    else
    {
        it->isDeclaration = 0;
        it->isCall = 1;
    }
    st->itemNames[st->top] = it;
    st->top = st->top + 1;
}

/**
 * @brief Print content of Stack
 * 
 * @param st stack of Tokens
 */
void stackPrint(Stack *st)
{

    for (int i = 0; i < st->top; i++)
    {
        printf("%s %s isDeclare = %d isCall = %d\n", getEnumName(st->itemNames[i]->type),
               st->itemNames[i]->name,
               st->itemNames[i]->isDeclaration,
               st->itemNames[i]->isCall);
    }
}

void checkUnusedVar(Stack *st)
{
}