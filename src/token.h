#ifndef TOKEN
#define TOKEN

#include <stdlib.h>
#include <stdio.h>

typedef enum Type_e {
	Operator,
	KeyWord,
	Delimiter,
	Variable,
	Numerical,
	Nothing
} Type;

typedef struct Token_t {
	Type type;
	char* value;
} Token;

typedef struct Ast_t {
	Token* base;
	Token* left;
	Token* right;
} ast;

Token* createToken(Type type, char* value);
#endif
