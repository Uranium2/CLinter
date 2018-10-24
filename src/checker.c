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
		printf("Expected %s. Found %s\n", getEnumName(type), getEnumName(tokens[*pos]->type));
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
			printf("Expected Operator. Found %s\n", getEnumName(tokens[*pos]->type));
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
	{
		printf("Expected Variable or Numerical. Found %s\n", getEnumName(tokens[*pos]->type));
	}
}

void keyword(Token **tokens, int *pos, int nbNode, char *val)
{
	if (!match(tokens[*pos], KeyWord, NULL))
	{
		printf("Expected Keyword. Found %s\n", getEnumName(tokens[*pos]->type));
	}
	if (val != NULL)
	{
		if (strcmp(val, tokens[*pos]->value) != 0)
			printf("Expected %s. Found %s\n", val, tokens[*pos]->value);
	}
	nextTok(pos, nbNode, tokens);
}

void varDeclare(Token **tokens, int *pos, int nbNode)
{
	keyword(tokens, pos, nbNode, NULL);
	if (match(tokens[*pos], Variable, NULL))
	{
		eatToken(tokens, Variable, pos, nbNode);
		if (match(tokens[*pos], Delimiter, ";"))
		{
			printf("END OF FILE\n");
		}
		else
		{
			if (match(tokens[*pos], Operator, "="))
			{
				eatToken(tokens, Operator, pos, nbNode);
				expression(tokens, pos, nbNode);
			}
			else
				printf("Expected '='. Found %s\n", tokens[*pos]->value);
		}
	}
	else
		printf("Expected Varaible. Found %s\n", getEnumName(tokens[*pos]->type));
}

void check(Token **tokens, int nbNode)
{

	for (int i = 0; i < nbNode; i++)
	{
		printf("%s", tokens[i]->value);
	}
	printf("\n");
	int pos = 0;
	varDeclare(tokens, &pos, nbNode);
}