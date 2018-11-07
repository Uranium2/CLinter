#include "checker.h"
/*
StartPoint	-> VarDeclare

VarDeclare	-> var ;
		|  var = Exp ;
		
Exp		-> num ;
		-> num Ope Exp
		-> var ;
		-> var Ope Exp
*/
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
	//printf("POSITION BEFORE: %d\n", *pos);
	if (*pos == nbNode - 1)
	{
		//printf("END OF FILE\n");
		return;
	}
	*pos = *pos + 1;
	while (match(tokens[*pos], Delimiter, " "))
		*pos = *pos + 1;
	//printf("POSITION AFTER: %d\n", *pos);
}

int eatToken(Token **tokens, Type type, int *pos, int nbNode)
{
	//printf("Before %d %d\n", *pos + 1, nbNode);
	if (tokens[*pos]->type != type) {
		//printErr(getEnumName(type), getEnumName(tokens[*pos]->type));
		return 0;
	}
	//printf("Eating token %s of type: %s %s \n", tokens[*pos]->value, getEnumName(tokens[*pos]->type), getEnumName(type));
	nextTok(pos, nbNode, tokens);
	//printf("After %d %d\n", *pos + 1, nbNode);
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

	//for (int i = 0; i < nbNode; i++)
	//	printf("%s", tokens[i]->value);
	//printf("\n");
	int pos = 0;
	varDeclare(tokens, &pos, nbNode);
}