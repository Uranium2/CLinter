#include "checker.h"

/**
* @file checker.c
* @brief This c file will contain all functions to check a grammar.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/

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
	while (match(tokens[*pos], Delimiter, " "))
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
	if (tokens[*pos]->type != type) {
		return 0;
	}
	nextTok(pos, nbNode, tokens);
	if (*pos + 1 == nbNode)
		exit(0);
	return 1;
}

/**
 * @brief Variables Declaration checker
 * 
 * @param tokens List of Tokens
 * @param pos Position in the list of Tokens
 * @param nbNode Number of tokens in the list
 */
void varDeclare(Token **tokens, int* pos, int nbNode)
{
	tokens = tokens;
	pos = pos;
	nbNode = nbNode;
	/*nextTok(pos, nbNode, tokens);
	if (eatToken(tokens, KeyWord, pos,nbNode))
			if (eatToken(tokens, IDENTIFIER, pos,nbNode))
				printf("Found Variable declaration\n");
				// Do something clever here
				*/
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