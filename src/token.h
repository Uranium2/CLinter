#ifndef TOKEN
#define TOKEN

#include <stdlib.h>
#include <stdio.h>

typedef enum Type_e
{
	// old types
	Operator,
	Delimiter,
	Variable,
	Numerical,
	KeyWord,
	// new types
	OpenPar,
	ClosedPar,
	COMA,
	IDENTIFIER,
	CONSTANT,
	STRING_LITERAL,
	PTR_OP,
	INC_OP,
	DEC_OP,
	SIZEOF,
	LEFT_OP,
	RIGHT_OP,
	LE_OP,
	GE_OP,
	EQ_OP,
	NE_OP,
	AND_OP,
	OR_OP,
	MUL_ASSIGN,
	DIV_ASSIGN,
	MOD_ASSIGN,
	ADD_ASSIGN,
	SUB_ASSIGN,
	LEFT_ASSIGN,
	RIGHT_ASSIGN,
	AND_ASSIGN,
	XOR_ASSIGN,
	OR_ASSIGN,
	TYPEDEF,
	EXTERN,
	STATIC,
	AUTO,
	REGISTER,
	VOID,
	CHAR,
	SHORT,
	INT,
	LONG,
	FLOAT,
	DOUBLE,
	SIGNED,
	UNSIGNED,
	TYPE_NAME,
	STRUCT,
	UNION,
	ENUM,
	CONST,
	VOLATILE,
	ELLIPSIS,
	CASE,
	DEFAULT,
	IF,
	ELSE,
	SWITCH,
	WHILE,
	DO,
	FOR,
	GOTO,
	CONTINUE,
	BREAK,
	RETURN,
	SPACE,
	TAB,
	Nothing
} Type;

typedef struct Token_t
{
	Type type;
	char *value;
} Token;

typedef struct Ast_t
{
	Token *base;
	Token *left;
	Token *right;
} ast;

char *getEnumName(Type type);

Token *createToken(Type type, char *value);
#endif
