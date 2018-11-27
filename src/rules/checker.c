/**
* @file checker.c
* @brief This c file will contain all functions to check a grammar.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#include "checker.h"

int getDoubleType(Token **tokens, int *pos, int nbNode);
int getSingleType(Token **tokens, int *pos, int nbNode);

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

    while (match(tokens[*pos], Delimiter, " ") || match(tokens[*pos], Delimiter, "\t"))
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
        exit(0);
    return 1;
}

int funcOrVar(Token **tokens, int *pos, int nbNode, char *type)
{
    if (eatToken(tokens, IDENTIFIER, pos, nbNode))
    {
        if (eatToken(tokens, OpenPar, pos, nbNode))
        {
            printf(RED "Found %s Function declaration\n" RESET, type);
            return 1;
        }
        else
        {
            printf(RED "Found %s Variable declaration\n" RESET, type);
            return 1;
        }
    }
    return 0;
}


int getType(Token **tokens, int *pos, int nbNode)
{
    if (eatToken(tokens, UNSIGNED, pos, nbNode))
    {
        if (eatToken(tokens, SHORT, pos, nbNode))
        {
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "UNSIGNED SHORT INT");
            return funcOrVar(tokens, pos, nbNode, "UNSIGNED SHORT");
        }
        if (eatToken(tokens, LONG, pos, nbNode))
        {
            if (eatToken(tokens, LONG, pos, nbNode))
            {
                if (eatToken(tokens, INT, pos, nbNode))
                    return funcOrVar(tokens, pos, nbNode, "UNSIGNED LONG LONG INT");
                return funcOrVar(tokens, pos, nbNode, "UNSIGNED LONG LONG");
            }
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "UNSIGNED LONG INT");
            return funcOrVar(tokens, pos, nbNode, "UNSIGNED LONG");
        }
        if (eatToken(tokens, INT, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "UNSIGNED INT");
        if (eatToken(tokens, CHAR, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "UNSIGNED CHAR");
        return funcOrVar(tokens, pos, nbNode, "UNSIGNED");
    }
    if (eatToken(tokens, SIGNED, pos, nbNode))
    {
        if (eatToken(tokens, SHORT, pos, nbNode))
        {
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "SIGNED SHORT INT");
            return funcOrVar(tokens, pos, nbNode, "SIGNED SHORT");
        }
        if (eatToken(tokens, LONG, pos, nbNode))
        {
            if (eatToken(tokens, LONG, pos, nbNode))
            {
                if (eatToken(tokens, INT, pos, nbNode))
                    return funcOrVar(tokens, pos, nbNode, "SIGNED LONG LONG INT");
                return funcOrVar(tokens, pos, nbNode, "SIGNED LONG LONG");
            }
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "SIGNED LONG INT");
            return funcOrVar(tokens, pos, nbNode, "SIGNED LONG");
        }
        if (eatToken(tokens, INT, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "SIGNED INT");
        if (eatToken(tokens, CHAR, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "SIGNED CHAR");
        return funcOrVar(tokens, pos, nbNode, "SIGNED");
    }
    if (eatToken(tokens, SHORT, pos, nbNode))
    {
        if (eatToken(tokens, INT, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "SHORT INT");
        return funcOrVar(tokens, pos, nbNode, "SHORT");
    }
    if (eatToken(tokens, LONG, pos, nbNode))
    {
        if (eatToken(tokens, LONG, pos, nbNode))
        {
            if (eatToken(tokens, INT, pos, nbNode))
                return funcOrVar(tokens, pos, nbNode, "LONG LONG INT");
            return funcOrVar(tokens, pos, nbNode, "LONG LONG");
        }
        if (eatToken(tokens, INT, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "LONG INT");
        if (eatToken(tokens, DOUBLE, pos, nbNode))
            return funcOrVar(tokens, pos, nbNode, "LONG DOUBLE");
        return funcOrVar(tokens, pos, nbNode, "LONG");
    }
    if (eatToken(tokens, INT, pos, nbNode))
        return funcOrVar(tokens, pos, nbNode, "INT");
    if (eatToken(tokens, DOUBLE, pos, nbNode))
        return funcOrVar(tokens, pos, nbNode, "DOUBLE");
    if (eatToken(tokens, FLOAT, pos, nbNode))
        return funcOrVar(tokens, pos, nbNode, "FLOAT");
    if (eatToken(tokens, CHAR, pos, nbNode))
        return funcOrVar(tokens, pos, nbNode, "CHAR");
    return 0;
}

/**
 * @brief Variables Declaration checker
 * 
 * @param tokens List of Tokens
 * @param pos Position in the list of Tokens
 * @param nbNode Number of tokens in the list
 */
void varDeclare(Token **tokens, int *pos, int nbNode)
{
    //printf("Pos before %d\n", *pos);
    nextTok(pos, nbNode, tokens);
    //printf("Pos after %d\n", *pos);
    getType(tokens, pos, nbNode);
    //printf("Pos after type %d\n", *pos);
    /*if (eatToken(tokens, KeyWord, pos, nbNode))
    {
        if (eatToken(tokens, IDENTIFIER, pos, nbNode))
        {
            if (eatToken(tokens, OpenPar, pos, nbNode))
                printf(RED "Found Function declaration\n" RESET);
            else
                printf(RED "Found Variable declaration\n" RESET);
        }
    }*/
    // Do something clever here
}

/**
 * @brief Checks a specific Grammar, not used at the moment
 * 
 * @param tokens List of Tokens
 * @param nbNode Number of nodes
 */
void check(Token **tokens, int nbNode)
{
    int pos = 0;
    varDeclare(tokens, &pos, nbNode);
}