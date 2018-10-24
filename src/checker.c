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
	if (*pos == nbNode - 1)
	{
		printf("END OF FILE\n");
		return;
	}
	*pos = *pos + 1;
	while (match(tokens[*pos], Delimiter, " "))
		*pos = *pos + 1;
}

void eatToken(Token **tokens, Type type, int *pos, int nbNode)
{
	printf("Eating token %s\n", tokens[*pos]->value);
	if (tokens[*pos]->type != type)
		printErr(getEnumName(type), getEnumName(tokens[*pos]->type));
	nextTok(pos, nbNode, tokens);
}

void expression(Token **tokens, int *pos, int nbNode)
{
	if (match(tokens[*pos], Numerical, NULL))
	{
		eatToken(tokens, Numerical, pos, nbNode);
		if (match(tokens[*pos], Delimiter, ";"))
		{
			printf("END OF FILE\n");
			return;
		}
		else if (match(tokens[*pos], Operator, NULL))
		{
			eatToken(tokens, Operator, pos, nbNode);
			expression(tokens, pos, nbNode);
			return;
		}
		else
			printErr("Operator", getEnumName(tokens[*pos]->type));
	}
	else if (match(tokens[*pos], Variable, NULL))
	{
		eatToken(tokens, Variable, pos, nbNode);
		if (match(tokens[*pos], Operator, NULL))
		{
			eatToken(tokens, Operator, pos, nbNode);
			expression(tokens, pos, nbNode);
		}
		else if (match(tokens[*pos], Delimiter, ";"))
		{
			printf("END OF FILE\n");
			return;
		}
	}
	else
		printErr("Variable or Numerical", getEnumName(tokens[*pos]->type));
}

void keyword(Token **tokens, int *pos, int nbNode, char *val)
{
	if (!match(tokens[*pos], KeyWord, NULL))
		printErr("Keyword", getEnumName(tokens[*pos]->type));
	if (val != NULL)
		if (strcmp(val, tokens[*pos]->value) != 0)
			printErr(val, tokens[*pos]->value);
	nextTok(pos, nbNode, tokens);
}

void varDeclare(Token **tokens, int *pos, int nbNode)
{
	keyword(tokens, pos, nbNode, NULL);
	if (match(tokens[*pos], Variable, NULL))
	{
		eatToken(tokens, Variable, pos, nbNode);
		if (match(tokens[*pos], Delimiter, ";"))
			printf("END OF FILE\n");
		else
		{
			if (match(tokens[*pos], Operator, "="))
			{
				eatToken(tokens, Operator, pos, nbNode);
				expression(tokens, pos, nbNode);
			}
			else
				printErr("=", tokens[*pos]->value);
		}
	}
	else
		printErr("Variable", getEnumName(tokens[*pos]->type));
}

void check(Token **tokens, int nbNode)
{

	for (int i = 0; i < nbNode; i++)
		printf("%s", tokens[i]->value);
	printf("\n");
	int pos = 0;
	varDeclare(tokens, &pos, nbNode);
}