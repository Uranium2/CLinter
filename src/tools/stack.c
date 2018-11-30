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
    stack->tokens = malloc(sizeof(Token *) * stack->size);
    stack->top = 0;
    return stack;
}

/**
 * @brief Push a new variable at the top of the Stack
 * 
 * @param st Stack of variables
 * @param tok Variable to push
 */
void stackPush(Stack *st, Token *tok)
{
    // check if stack is full
    st->tokens[st->top] = tok;
    st->top = st->top + 1;
}

/** 
 * @brief Pop the last variable at the top of the Stack
 * 
 * @param st Stack of variables
 */
void stackPop(Stack *st)
{
}
