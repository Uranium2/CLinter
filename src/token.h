#ifndef TOKEN
#define TOKEN

#include <stdlib.h>
#include <stdio.h>

typedef struct Token_t {
	int type; // 0 = Operator
	// 1 = KeyWord
	// 2 = Delimiter
	// 3 = Variable
	// 4 = Num
	// 5 = ??
	char* value;
} Token;

typedef struct Ast_t {
	Token* base;
	Token* left;
	Token* right;
} ast;

Token* createToken(int type, char* value);
#endif
