#ifndef TOKEN
#define TOKEN

/**
* @file token.h
* @brief This header file will contain all required
* definitions and basic utilities functions to create a Token.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Enumeration to store type of a Token
 * 
 */
typedef enum Type_e
{
	// old types
	Operator,
	Delimiter,
	Variable,
	Numerical,
	KeyWord,
	Var_type,
	// new types
	OpenPar,
	ClosedPar,
	OpenBracket,
	ClosedBracket,
	DotComa,
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

/**
 * @brief Structure to store a Token
 * 
 */
typedef struct Token_t
{
	Type type; /**< The type of the Token. */
	char *value; /**< The string representation of the Token. */
	int pos; /**< The position of the Token in the list of characters of a line. */
} Token;

/**
 * @brief Get the Enum Name of a Type
 * 
 * @param type Given Type
 * @return char* Type cast to string
 */
char* getEnumName(Type type);

/**
 * @brief Create a Token structure
 * 
 * @param type Given Type
 * @param value Given String value
 * @param pos Given position of the Token in a line 
 * @return Token* A new Token
 */
Token *createToken(Type type, char *value, int pos);
#endif
