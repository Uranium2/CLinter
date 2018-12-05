#include "stack.h"

/**
 * @brief Warns the user if a variable is declared but not used
 * 
 * @param st Stack of variable/functions names
 */
void checkUnusedVar(Stack *st, char *file)
{
    for (int o = 1; o < st->posTopBase + 1; o++)
    {
        for (int i = st->base[o]; i < st->top[o]; i++)
        {
            if (!st->itemNames[i]->isDeclaration || !st->itemNames[i]->isVar)
                continue;
            int seen = 0;
            for (int j = i + 1; j < st->top[o]; j++)
            {
                if (st->itemNames[i]->isDeclaration && st->itemNames[j]->isCall &&
                    strcmp(st->itemNames[i]->name, st->itemNames[j]->name) == 0)
                {
                    seen = 1;
                    break;
                }
            }
            if (seen != 1)
            {
                printf(RED "%s " YEL "variable not used at line %d in file %s\n" RESET, st->itemNames[i]->name, st->itemNames[i]->line, file);
            }
        }
    }
}

/**
 * @brief Warns the user if a function is declared but not used
 * 
 * @param st Stack of variable/functions names
 */
void checkUnusedFunc(Stack *st, char *file)
{
    for (int i = 0; i < st->top[st->posTopBase]; i++)
    {
        if (!st->itemNames[i]->isDeclaration || st->itemNames[i]->isVar)
            continue;
        int seen = 0;
        for (int j = i + 1; j < st->top[st->posTopBase]; j++)
        {
            if (st->itemNames[i]->isDeclaration && st->itemNames[j]->isCall &&
                strcmp(st->itemNames[i]->name, st->itemNames[j]->name) == 0)
            {
                seen = 1;
                break;
            }
        }
        if (seen != 1)
        {
            printf(RED "%s " YEL "function not used at line %d in file %s\n" RESET, st->itemNames[i]->name, st->itemNames[i]->line, file);
        }
    }
}

/**
 * @brief Warns the user if a variable is used but not declared
 * 
 * @param st Stack of variable/functions names
 */
void checkUndeclaredVar(Stack *st, char *file)
{

    for (int o = 1; o < st->posTopBase + 1; o++)
    {
        for (int i = st->top[o] - 1; i != st->base[o]; i--)
        {
            if (st->itemNames[i]->isDeclaration || !st->itemNames[i]->isVar)
                continue;
            int seen = 0;
            for (int j = i - 1; j != st->base[o]; j--)
            {
                if (strcmp(st->itemNames[i]->name, st->itemNames[j]->name) == 0 && st->itemNames[j]->isDeclaration)
                {
                    seen = 1;
                    break;
                }
            }
            if (seen == 0)
            {
                printf(RED "%s " YEL "variable not declared at line %d in file %s\n" RESET, st->itemNames[i]->name, st->itemNames[i]->line, file);
            }
        }
    }
}

/**
 * @brief Warns the user if a variable is used but not declared
 * 
 * @param st Stack of variable/functions names
 */
void checkUndeclaredFunc(Stack *st, char *file)
{
    for (int i = st->top[st->posTopBase] - 1; i != st->base[st->posTopBase]; i--)
    {
        if (st->itemNames[i]->isDeclaration || st->itemNames[i]->isVar)
            continue;
        int seen = 0;
        for (int j = i - 1; j != st->base[st->posTopBase]; j--)
        {
            if (strcmp(st->itemNames[i]->name, st->itemNames[j]->name) == 0 && st->itemNames[j]->isDeclaration)
            {
                seen = 1;
                break;
            }
        }
        if (seen == 0)
        {
            printf(RED "%s " YEL "function not declared at line %d in file %s\n" RESET, st->itemNames[i]->name, st->itemNames[i]->line, file);
        }
    }
}

/**
 * @brief Create a new empty call Stack
 * 
 * @return Stack* Pointer to an empty call stack
 */
Stack *stackInit()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->size = 5;
    stack->itemNames = malloc(sizeof(ItemName *) * stack->size);
    stack->top = malloc(sizeof(int) * stack->size);
    stack->base = malloc(sizeof(int) * stack->size);
    stack->posTopBase = 0;
    stack->top[stack->posTopBase] = 0;
    stack->base[stack->posTopBase] = 0;
    return stack;
}

/**
 * @brief Push an existing itemName in the stack. Usefull for copy data
 * 
 * @param st Stack of variables
 * @param tok Variable to push
 */
void stackPushItem(Stack *st, ItemName *it)
{
    // check if stack is full
    if (st->size == st->top[st->posTopBase] || st->size == st->posTopBase)
    {
        st->size = st->size * 2;
        st->top = realloc(st->top, sizeof(int *) * st->size);
        st->base = realloc(st->base, sizeof(int *) * st->size);
        st->itemNames = realloc(st->itemNames, sizeof(int *) * st->size);
    }
    st->itemNames[st->top[st->posTopBase]] = it;
    st->top[st->posTopBase] = st->top[st->posTopBase] + 1;
}

void stackRemoveScope(Stack *st)
{
    if (st->posTopBase == 0)
        return;
    st->posTopBase = st->posTopBase - 1;
}

/**
 * @brief Update Stack MetaData to create a virtual scope in the stack
 * 
 * @param st Stack of variables
 */
void stackAddScope(Stack *st)
{
    //int oldBase = st->base[st->posTopBase];
    int oldTop = st->top[st->posTopBase];
    int newBase = oldTop;

    st->posTopBase = st->posTopBase + 1;
    st->base[st->posTopBase] = newBase;
    st->top[st->posTopBase] = newBase;

    //for (int i = oldBase; i < oldTop; i++)
    //    stackPushItem(st, st->itemNames[i]);
}

/**
 * @brief Push a new variable at the top of the Stack
 * 
 * @param st Stack of variables
 * @param tok Variable to push
 */
void stackPush(Stack *st, Token *tok, int isDeclaration, int isCall, int varOrFunc, char *type)
{
    // check if stack is full
    if (st->size == st->top[st->posTopBase] || st->size == st->posTopBase)
    {
        st->size = st->size * 2;
        st->top = realloc(st->top, sizeof(int *) * st->size);
        st->base = realloc(st->base, sizeof(int *) * st->size);
        st->itemNames = realloc(st->itemNames, sizeof(int *) * st->size);
    }
    // Do stuff
    ItemName *it = malloc(sizeof(ItemName));
    it->name = tok->value;
    it->type = type;
    it->isDeclaration = isDeclaration;
    it->isCall = isCall;
    it->line = tok->pos;
    if (varOrFunc)
        it->isVar = 1;
    else
        it->isVar = 0;

    st->itemNames[st->top[st->posTopBase]] = it;
    st->top[st->posTopBase] = st->top[st->posTopBase] + 1;
}

/**
 * @brief Print content of Stack
 * 
 * @param st stack of Tokens
 */
void stackPrint(Stack *st)
{

    for (int i = 0; i < st->top[st->posTopBase]; i++)
    {
        printf("%s isDeclare = %d isCall = %d isVar = %d type = %s\n",
               st->itemNames[i]->name,
               st->itemNames[i]->isDeclaration,
               st->itemNames[i]->isCall, st->itemNames[i]->isVar,
               st->itemNames[i]->type);
    }

    for (int i = 0; i <= st->posTopBase; i++)
    {
        printf("top = %d base = %d\n", st->top[i], st->base[i]);
    }
}