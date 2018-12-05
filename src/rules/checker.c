/**
* @file checker.c
* @brief This c file will contain all functions to check a grammar.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#include "checker.h"


/**
 * @brief Debug function to print Grammar errors
 * 
 * @param expected String expected
 * @param found  String found
 */
void printErr(char *expected, char *found)
{
    printf("Expected %s. Found %s at line X char Y\n", expected, found);
}

/**
 * @brief  Check if the Type matchs the type of the Token and the string content of the Token
 * 
 * @param tok Specific Token
 * @param type Wanted Type to check
 * @param val String to check
 * @return int 0 false else true
 */
int match(Token *tok, Type type, char *val)
{
    if (type == tok->type)
    {
        if (val == NULL)
            return 1;
        return (strcmp(val, tok->value) == 0);
    }
    return 0;
}

/**
 * @brief Updates the position value
 * 
 * @param pos Position in the list of Tokens
 * @param nbNode Number of tokens in the list of Tokens
 * @param tokens List of Tokens
 */
void nextTok(int *pos, int nbNode, Token **tokens)
{
    if (*pos == nbNode - 1)
    {
        return;
    }
    *pos = *pos + 1;

    while (match(tokens[*pos], Delimiter, " ") || match(tokens[*pos], Delimiter, "\t") || tokens[*pos]->type == Delimiter)
        *pos = *pos + 1;
}

/**
 * @brief Tries to go to the next Token
 * 
 * @param tokens List of Tokens
 * @param type Type of the expected Token
 * @param pos Position in the list of Tokens
 * @param nbNode Number of tokens in the list
 * @return int 0 false else true
 */
int eatToken(Token **tokens, Type type, int *pos, int nbNode)
{
    if (tokens[*pos]->type != type)
    {
        return 0;
    }
    nextTok(pos, nbNode, tokens);
    if (*pos + 1 == nbNode)
        return 0;
    return 1;
}

/**
 * @brief Determines if the given token is a varirable or a function 
 * 
 * @param tokens List of Tokens
 * @param pos Position in the list of tokens
 * @param nbNode Number of nodes
 * @param type Type of the variable/function
 * @return int 0 false else true
 */
int funcOrVar(Token **tokens, int *pos, int nbNode, char *type, Stack *stack, Collector *c)
{
    int pointer = 0;
    while (eatToken(tokens, MUL_ASSIGN, pos, nbNode))
        pointer++;

    int posID = *pos;
    if (eatToken(tokens, IDENTIFIER, pos, nbNode))
    {

        if (eatToken(tokens, OpenPar, pos, nbNode))
        {
            //stackRemoveScope(stack);
            stackAddScope(stack);
            stackPush(stack, tokens[posID], 1, 0, 0, type, c);
            return 1;
        }
        else
        {
            stackPush(stack, tokens[posID], 1, 0, 1, type, c);
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Finds a variable/function call (not declaration)
 * 
 * @param tokens List of Tokens
 * @param pos Position in the list of tokens
 * @param nbNode Number of nodes
 * @return int 0 false else true
 */
int getCall(Token **tokens, int *pos, int nbNode, Stack *stack, Collector *c)
{
    int pointer = 0;
    while (eatToken(tokens, MUL_ASSIGN, pos, nbNode))
        pointer++;

    int posID = *pos;
    if (eatToken(tokens, IDENTIFIER, pos, nbNode))
    {

        if (eatToken(tokens, OpenPar, pos, nbNode))
        {
            stackPush(stack, tokens[posID], 0, 1, 0, "", c);
        }
        else
        {
            stackPush(stack, tokens[posID], 0, 1, 1, "", c);
        }
        return 1;
    }
    return 0;
}

/**
 * @brief Get the Type of a Variable or Function
 * 
 * @param tokens List of Tokens
 * @param pos Position in the list of tokens
 * @param nbNode Number of nodes
 * @return int 0 false else true
 */
int getType(Token **tokens, int *pos, int nbNode, Stack *stack, Collector *c)
{
    if (eatToken(tokens, UNSIGNED, pos, nbNode))
    {
        if (eatToken(tokens, SHORT, pos, nbNode))
        {
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "UNSIGNED SHORT INT", stack, c);
            return funcOrVar(tokens, pos, nbNode, "UNSIGNED SHORT", stack, c);
        }
        if (eatToken(tokens, LONG, pos, nbNode))
        {
            if (eatToken(tokens, LONG, pos, nbNode))
            {
                if (eatToken(tokens, INT, pos, nbNode))
                    return funcOrVar(tokens, pos, nbNode, "UNSIGNED LONG LONG INT", stack, c);
                return funcOrVar(tokens, pos, nbNode, "UNSIGNED LONG LONG", stack, c);
            }
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "UNSIGNED LONG INT", stack, c);
            return funcOrVar(tokens, pos, nbNode, "UNSIGNED LONG", stack, c);
        }
        if (eatToken(tokens, INT, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "UNSIGNED INT", stack, c);
        if (eatToken(tokens, CHAR, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "UNSIGNED CHAR", stack, c);
        return funcOrVar(tokens, pos, nbNode, "UNSIGNED", stack, c);
    }
    if (eatToken(tokens, SIGNED, pos, nbNode))
    {
        if (eatToken(tokens, SHORT, pos, nbNode))
        {
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "SIGNED SHORT INT", stack, c);
            return funcOrVar(tokens, pos, nbNode, "SIGNED SHORT", stack, c);
        }
        if (eatToken(tokens, LONG, pos, nbNode))
        {
            if (eatToken(tokens, LONG, pos, nbNode))
            {
                if (eatToken(tokens, INT, pos, nbNode))
                    return funcOrVar(tokens, pos, nbNode, "SIGNED LONG LONG INT", stack, c);
                return funcOrVar(tokens, pos, nbNode, "SIGNED LONG LONG", stack, c);
            }
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "SIGNED LONG INT", stack, c);
            return funcOrVar(tokens, pos, nbNode, "SIGNED LONG", stack, c);
        }
        if (eatToken(tokens, INT, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "SIGNED INT", stack, c);
        if (eatToken(tokens, CHAR, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "SIGNED CHAR", stack, c);
        return funcOrVar(tokens, pos, nbNode, "SIGNED", stack, c);
    }
    if (eatToken(tokens, SHORT, pos, nbNode))
    {
        if (eatToken(tokens, INT, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "SHORT INT", stack, c);
        return funcOrVar(tokens, pos, nbNode, "SHORT", stack, c);
    }
    if (eatToken(tokens, LONG, pos, nbNode))
    {
        if (eatToken(tokens, LONG, pos, nbNode))
        {
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "LONG LONG INT", stack, c);
            return funcOrVar(tokens, pos, nbNode, "LONG LONG", stack, c);
        }
        if (eatToken(tokens, INT, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "LONG INT", stack, c);
        if (eatToken(tokens, DOUBLE, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "LONG DOUBLE", stack, c);
        return funcOrVar(tokens, pos, nbNode, "LONG", stack, c);
    }
    if (eatToken(tokens, INT, pos, nbNode))
        return funcOrVar(tokens, pos, nbNode, "INT", stack, c);
    if (eatToken(tokens, DOUBLE, pos, nbNode))
        return funcOrVar(tokens, pos, nbNode, "DOUBLE", stack, c);
    if (eatToken(tokens, FLOAT, pos, nbNode))
        return funcOrVar(tokens, pos, nbNode, "FLOAT", stack, c);
    if (eatToken(tokens, CHAR, pos, nbNode))
        return funcOrVar(tokens, pos, nbNode, "CHAR", stack, c);
    return 0;
}

/**
 * @brief Variables Declaration checker
 * 
 * @param tokens List of Tokens
 * @param pos Position in the list of Tokens
 * @param nbNode Number of tokens in the list
 */
void varDeclare(Token **tokens, int *pos, int nbNode, Stack *stack, Collector *c)
{
    while (*pos != nbNode)
    {
        getCall(tokens, pos, nbNode, stack, c);
        if (getType(tokens, pos, nbNode, stack, c))
            *pos = *pos - 1;
        *pos = *pos + 1;
    }
}

/**
 * @brief Checks a specific Grammar, not used at the moment
 * 
 * @param tokens List of Tokens
 * @param nbNode Number of nodes
 */
void check(Token **tokens, int nbNode, Stack *stack, Collector *c)
{
    int pos = 0;
    varDeclare(tokens, &pos, nbNode, stack, c);
}

/**
 * @brief Check if the list of Tokens contains a specific string
 *
 * @param listToken List of Tokens
 * @param nbToken Numbers of Tokens
 * @param str String to check
 * @return int 0 false else true
 */
int containsStr(Token **listToken, int nbToken, char *str)
{
    for (int i = 0; i < nbToken; i++)
        if (strcmp(listToken[i]->value, str) == 0)
            return i;
    return 0;
}