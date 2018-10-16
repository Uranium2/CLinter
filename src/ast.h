#ifndef AST
#define AST

#include <stdlib.h>
#include <stdio.h>

typedef struct AstNode_t {
	int type; // 0 = Operator
	// 1 = KeyWord
	// 2 = Delimiter
	// 3 = Variable
	// 4 = Num
	// 5 = ??
	char* value;
} AstNode;

typedef struct Ast_t {
	AstNode* base;
	AstNode* left;
	AstNode* right;
} ast;

AstNode* createNode(int type, char* value);
#endif
