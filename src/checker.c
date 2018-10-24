#include "checker.h"

int isAssign(Token **listToken, int pos)
{
	//int size = sizeof(listToken) / sizeof(listToken[0]);
	if (!strcmp(listToken[pos + 4]->value, "="))
		return 1;
	return 0;
}

/*
StartPoint	-> VarDeclare

VarDeclare	-> var ;
		|  var = Exp ;
		
Exp		-> num ;
		-> num Ope Exp
		-> var ;
		-> var Ope Exp
*/
void nextTok(int *pos, int nbNode, Token **tokens)
{
	if (*pos == nbNode - 1)
	{
		printf("END OF FILE\n");
		return;
	}
	printf("At token: %s type %s pos %d\n", tokens[*pos]->value, getEnumName(tokens[*pos]->type), *pos);
	*pos = *pos + 1;
	while (strcmp(tokens[*pos]->value, " ") == 0)
		*pos = *pos + 1;
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

void var(Token **tokens, int *pos, int nbNode)
{
	if (tokens[*pos]->type != Variable)
		printf("Expected Variable. Found %s\n", getEnumName(tokens[*pos]->type));
	nextTok(pos, nbNode, tokens);
}

void numerical(Token **tokens, int *pos, int nbNode)
{
	if (tokens[*pos]->type != Numerical)
		printf("Expected Numerical. Found %s\n", getEnumName(tokens[*pos]->type));
	nextTok(pos, nbNode, tokens);
}

void operator(Token **tokens, int *pos, int nbNode)
{
	if (tokens[*pos]->type != Operator)
		printf("Expected Operator. Found %s\n", getEnumName(tokens[*pos]->type));
	nextTok(pos, nbNode, tokens);
}

void delimiter(Token **tokens, int *pos, int nbNode)
{
	if (tokens[*pos]->type != Delimiter)
		printf("Expected Delimiter. Found %s\n", getEnumName(tokens[*pos]->type));
	nextTok(pos, nbNode, tokens);
}

void expression(Token **tokens, int *pos, int nbNode)
{
	if (match(tokens[*pos], Numerical, NULL))
	{
		numerical(tokens, pos, nbNode);
		if (match(tokens[*pos], Delimiter, ";"))
		{
			printf("END OF FILE\n");
			return;
		}
		else if (match(tokens[*pos], Operator, NULL))
		{
			operator(tokens, pos, nbNode);
			expression(tokens, pos, nbNode);
			return;
		}
		else
			printf("Expected Operator. Found %s\n", getEnumName(tokens[*pos]->type));
	}
	else if (match(tokens[*pos], Variable, NULL))
	{
		var(tokens, pos, nbNode);
		if (match(tokens[*pos], Operator, NULL))
		{
			operator(tokens, pos, nbNode);
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

void equal(Token **tokens, int *pos, int nbNode)
{
	if (tokens[*pos]->type != Operator)
	{
		printf("Expected Operator. Found %s\n", getEnumName(tokens[*pos]->type));
	}
	nextTok(pos, nbNode, tokens);
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
		var(tokens, pos, nbNode);
		if (match(tokens[*pos], Delimiter, ";"))
		{
			printf("END OF FILE\n");
		}
		else
		{
			if (match(tokens[*pos], Operator, "="))
			{
				equal(tokens, pos, nbNode);
				expression(tokens, pos, nbNode);
			}
			else
				printf("Expected '='. Found %s\n", tokens[*pos]->value);
		}
	}
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