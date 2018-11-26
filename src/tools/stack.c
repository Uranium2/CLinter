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
    
    for(int i = st->baseTopArray[st->posBaseTop - 2]; i < st->baseTopArray[st->posBaseTop]; i++)
    {
        if (strcmp(st->stack[i].value , token.value) == 0)
            return 1;
    }
    return 0;
}

/**
 * @brief Create a new empty call Stack
 * 
 * @return Stack* Pointer to an empty call stack
 */
Stack *stackInit()
{
    Stack *st = malloc(sizeof(Stack));
    st->capacity = 10;
    st->capPos = 10;

    st->posStack = -1;
    st->posBaseTop = -1;

    st->stack = malloc(sizeof(Token) * st->capacity);
    st->baseTopArray = malloc(sizeof(int) * st->capPos);

    return st;
}

/**
 * @brief Check if stack is empty
 * 
 * @param st Stack of variables
 * @return int 0 not empty else empty
 */
int isEmpty(Stack *st)
{
    return st->capacity == -1;
}

/**
 * @brief Function to call when we encounter a function call
 * 
 * @param st Stack of variables
 * @param list of Tokens
 * @param number of tokens in the list
 */
void functionCall(Stack *st, Token *tokens, int nbToken)
{
    // get name of fonction in tokens
    st = st;
    tokens = tokens;
    nbToken = nbToken;
    for(int i = 0; i < nbToken; i++)
    {
        /* code */
    }
    
    // get variable in function declaration
    // update position base and top (base = top, top = top)
    // increment of 2 posBaseTop (base and top cell)
    // push all the tokens
}

/**
 * @brief Push a new variable at the top of the Stack
 * 
 * @param st Stack of variables
 * @param tok Variable to push
 */
void stackPush(Stack *st, Token *tok)
{
    if (st->capacity == st->posStack || st->capPos == st->posBaseTop)
    {
        // realloc Stack and baseTopArray and double capacity
    }

    st->posStack++;
    st->stack[st->posStack] = *tok;
    st->baseTopArray[st->posBaseTop]++;
}

/** 
 * @brief Pop the last variable at the top of the Stack
 * 
 * @param st Stack of variables
 */
void stackPop(Stack *st)
{
    st->posStack--;
    st->baseTopArray[st->posBaseTop]--;
}

/**
 * @brief Retrieve the state of the stack before function call
 * 
 * @param st Stack of variables
 */
void endFunctionCall(Stack *st)
{
    // update position of base and top
    st->posBaseTop -= 2;

}