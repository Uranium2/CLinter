#ifndef TOKEN
#define TOKEN

#include <stdlib.h>
#include <stdio.h>

typedef enum Type_e
{
	Operator,
	KeyWord,
	Delimiter,
	Variable,
	Numerical,
	Nothing
} Type;

typedef struct Token_t
{
	Type type;
	char *value;
	int pos;
} Token;

char* getEnumName(Type type);

Token *createToken(Type type, char *value, int pos);
#endif
