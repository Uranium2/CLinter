#include "checker.h"

void printErr(char *expected, char *found)
{
	printf("Expected %s. Found %s at line X char Y\n", expected, found);
}
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

void varDeclare(Token **tokens, int* pos, int nbNode)
{
	tokens =tokens;
	pos = pos;
	nbNode = nbNode;
}

void check(Token **tokens, int nbNode)
{
	int pos = 0;
	varDeclare(tokens, &pos, nbNode);
}