#include "stack.h"

/**
 * @brief Warns the user if a variable is declared but not used
 * 
 * @param st Stack of variable/functions names
 */
void checkUnusedVar(Stack *st, char *file)
{

    for (int i = 0; i < st->top; i++)
    {
        if (!st->itemNames[i]->isDeclaration || !st->itemNames[i]->isVar)
            continue;
        int seen = 0;
        for (int j = i + 1; j < st->top; j++)
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
            printf(RED "%s " YEL "variable not used at line %d in file %s\n" RESET, st->itemNames[i]->name, i, file);
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
    for (int i = 0; i < st->top; i++)
    {
        if (!st->itemNames[i]->isDeclaration || st->itemNames[i]->isVar)
            continue;
        int seen = 0;
        for (int j = i + 1; j < st->top; j++)
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
            printf(RED "%s " YEL "function not used at line %d in file %s\n" RESET, st->itemNames[i]->name, i, file);
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
    for (int i = st->top - 1; i != 0; i--)
    {
        if (st->itemNames[i]->isDeclaration || !st->itemNames[i]->isVar)
            continue;
        int seen = 0;
        for (int j = i - 1; j != 0; j--)
        {
            if (strcmp(st->itemNames[i]->name, st->itemNames[j]->name) == 0 && st->itemNames[j]->isDeclaration)
            {
                seen = 1;
                break;
            }
        }
        if (seen == 0)
        {
            printf(RED "%s " YEL "variable not declared at line %d in file %s\n" RESET, st->itemNames[i]->name, i, file);
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
    for (int i = st->top - 1; i != 0; i--)
    {
        if (st->itemNames[i]->isDeclaration || st->itemNames[i]->isVar)
            continue;
        int seen = 0;
        for (int j = i - 1; j != 0; j--)
        {
            if (strcmp(st->itemNames[i]->name, st->itemNames[j]->name) == 0 && st->itemNames[j]->isDeclaration)
            {
                seen = 1;
                break;
            }
        }
        if (seen == 0)
        {
            printf(RED "%s " YEL "function not declared at line %d in file %s\n" RESET, st->itemNames[i]->name, i, file);
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
void stackPush(Stack *st, Token *tok, int typeOfPush, int varOrFunc, char *type)
{
    // check if stack is full
    // Do stuff
    ItemName *it = malloc(sizeof(ItemName));
    it->name = tok->value;
    it->type = type;
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
    if (varOrFunc)
        it->isVar = 1;
    else
        it->isVar = 0;

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
        printf("%s isDeclare = %d isCall = %d isVar = %d type = %s\n",
               st->itemNames[i]->name,
               st->itemNames[i]->isDeclaration,
               st->itemNames[i]->isCall, st->itemNames[i]->isVar,
               st->itemNames[i]->type);
    }
}