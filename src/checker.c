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
int primary_expression(Token **tokens, int *pos, int nbNode);
int postfix_expression(Token **tokens, int *pos, int nbNode);
int argument_expression_list(Token **tokens, int *pos, int nbNode);
int unary_expression(Token **tokens, int *pos, int nbNode);
int unary_operator(Token **tokens, int *pos, int nbNode);
int cast_expression(Token **tokens, int *pos, int nbNode);
int multiplicative_expression(Token **tokens, int *pos, int nbNode);
int additive_expression(Token **tokens, int *pos, int nbNode);
int shift_expression(Token **tokens, int *pos, int nbNode);
int relational_expression(Token **tokens, int *pos, int nbNode);
int equality_expression(Token **tokens, int *pos, int nbNode);
int and_expression(Token **tokens, int *pos, int nbNode);
int exclusive_or_expression(Token **tokens, int *pos, int nbNode);
int inclusive_or_expression(Token **tokens, int *pos, int nbNode);
int logical_and_expression(Token **tokens, int *pos, int nbNode);
int logical_or_expression(Token **tokens, int *pos, int nbNode);
int conditional_expression(Token **tokens, int *pos, int nbNode);
int assignment_expression(Token **tokens, int *pos, int nbNode);
int assignment_operator(Token **tokens, int *pos, int nbNode);
int expression(Token **tokens, int *pos, int nbNode);
int constant_expression(Token **tokens, int *pos, int nbNode);
int declaration(Token **tokens, int *pos, int nbNode);
int declaration_specifiers(Token **tokens, int *pos, int nbNode);
int init_declarator_list(Token **tokens, int *pos, int nbNode);
int init_declarator(Token **tokens, int *pos, int nbNode);
int storage_class_specifier(Token **tokens, int *pos, int nbNode);
int type_specifier(Token **tokens, int *pos, int nbNode);
int struct_or_union_specifier(Token **tokens, int *pos, int nbNode);
int struct_or_union(Token **tokens, int *pos, int nbNode);
int struct_declaration_list(Token **tokens, int *pos, int nbNode);
int struct_declaration(Token **tokens, int *pos, int nbNode);
int specifier_qualifier_list(Token **tokens, int *pos, int nbNode);
int struct_declarator_list(Token **tokens, int *pos, int nbNode);
int struct_declarator(Token **tokens, int *pos, int nbNode);
int enum_specifier(Token **tokens, int *pos, int nbNode);
int enumerator_list(Token **tokens, int *pos, int nbNode);
int enumerator(Token **tokens, int *pos, int nbNode);
int type_qualifier(Token **tokens, int *pos, int nbNode);
int declarator(Token **tokens, int *pos, int nbNode);
int direct_declarator(Token **tokens, int *pos, int nbNode);
int pointer(Token **tokens, int *pos, int nbNode);
int type_qualifier_list(Token **tokens, int *pos, int nbNode);
int parameter_type_list(Token **tokens, int *pos, int nbNode);
int parameter_list(Token **tokens, int *pos, int nbNode);
int parameter_declaration(Token **tokens, int *pos, int nbNode);
int identifier_list(Token **tokens, int *pos, int nbNode);
int type_name(Token **tokens, int *pos, int nbNode);
int abstract_declarator(Token **tokens, int *pos, int nbNode);
int direct_abstract_declarator(Token **tokens, int *pos, int nbNode);
int initializer(Token **tokens, int *pos, int nbNode);
int initializer_list(Token **tokens, int *pos, int nbNode);
int statement(Token **tokens, int *pos, int nbNode);
int labeled_statement(Token **tokens, int *pos, int nbNode);
int compound_statement(Token **tokens, int *pos, int nbNode);
int declaration_list(Token **tokens, int *pos, int nbNode);
int statement_list(Token **tokens, int *pos, int nbNode);
int expression_statement(Token **tokens, int *pos, int nbNode);
int selection_statement(Token **tokens, int *pos, int nbNode);
int iteration_statement(Token **tokens, int *pos, int nbNode);
int jump_statement(Token **tokens, int *pos, int nbNode);
int translation_unit(Token **tokens, int *pos, int nbNode);
int external_declaration(Token **tokens, int *pos, int nbNode);
int function_definition(Token **tokens, int *pos, int nbNode);

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
	printf("POSITION BEFORE: %d\n", *pos);
	if (*pos == nbNode - 1)
	{
		printf("END OF FILE\n");
		return;
	}
	*pos = *pos + 1;
	while (match(tokens[*pos], Delimiter, " "))
		*pos = *pos + 1;
	printf("POSITION AFTER: %d\n", *pos);
}

int eatToken(Token **tokens, Type type, int *pos, int nbNode)
{
	//printf("Before %d %d\n", *pos + 1, nbNode);
	if (tokens[*pos]->type != type) {
		//printErr(getEnumName(type), getEnumName(tokens[*pos]->type));
		return 0;
	}
	printf("Eating token %s of type: %s %s \n", tokens[*pos]->value, getEnumName(tokens[*pos]->type), getEnumName(type));
	nextTok(pos, nbNode, tokens);
	//printf("After %d %d\n", *pos + 1, nbNode);
	if (*pos + 1 == nbNode)
		exit(0);
	return 1;
}

int primary_expression(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, IDENTIFIER, pos, nbNode))
		return 1;

	if (eatToken(tokens, CONSTANT, pos, nbNode))
		return 1;

	if (eatToken(tokens, STRING_LITERAL, pos, nbNode))
		return 1;

	if (eatToken(tokens, OpenPar, pos, nbNode))
	{
		if (expression(tokens, pos, nbNode))
			return eatToken(tokens, ClosedPar, pos, nbNode);
	}

	return 0;
}

int postfix_expression(Token **tokens, int *pos, int nbNode)
{
	if (primary_expression(tokens, pos, nbNode))
		return 1;

	if (postfix_expression(tokens, pos, nbNode))
	{
		if (eatToken(tokens, '[', pos, nbNode))
		{
			if (expression(tokens, pos, nbNode))
				return eatToken(tokens, ']', pos, nbNode);
			return 0;
		}

		if (eatToken(tokens, OpenPar, pos, nbNode))
		{
			if (eatToken(tokens, ClosedPar, pos, nbNode))
				return 1;
			if (argument_expression_list(tokens, pos, nbNode))
				return eatToken(tokens, ClosedPar, pos, nbNode);
			return 0;
		}

		if (eatToken(tokens, '.', pos, nbNode))
			return eatToken(tokens, IDENTIFIER, pos, nbNode);

		if (eatToken(tokens, PTR_OP, pos, nbNode))
			return eatToken(tokens, IDENTIFIER, pos, nbNode);

		if (eatToken(tokens, INC_OP, pos, nbNode))
			return 1;

		if (eatToken(tokens, DEC_OP, pos, nbNode))
			return 1;
	}
	return 0;
}

int argument_expression_list(Token **tokens, int *pos, int nbNode)
{
	if (assignment_expression(tokens, pos, nbNode))
		return 1;

	if (argument_expression_list(tokens, pos, nbNode))
	{
		if (eatToken(tokens, COMA, pos, nbNode))
			return assignment_expression(tokens, pos, nbNode);
	}
	return 0;
}

int unary_expression(Token **tokens, int *pos, int nbNode)
{
	if (postfix_expression(tokens, pos, nbNode))
		return 1;

	if (eatToken(tokens, INC_OP, pos, nbNode))
		return unary_expression(tokens, pos, nbNode);

	if (eatToken(tokens, DEC_OP, pos, nbNode))
		return unary_expression(tokens, pos, nbNode);

	if (unary_operator(tokens, pos, nbNode))
		return cast_expression(tokens, pos, nbNode);

	if (eatToken(tokens, SIZEOF, pos, nbNode))
	{
		if (unary_expression(tokens, pos, nbNode))
			return 1;
		if (eatToken(tokens, OpenPar, pos, nbNode))
			if (type_name(tokens, pos, nbNode))
				return eatToken(tokens, ClosedPar, pos, nbNode);
	}

	return 0;
}

int unary_operator(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, '&', pos, nbNode))
		return 1;

	if (eatToken(tokens, '*', pos, nbNode))
		return 1;

	if (eatToken(tokens, '+', pos, nbNode))
		return 1;

	if (eatToken(tokens, '-', pos, nbNode))
		return 1;

	if (eatToken(tokens, '~', pos, nbNode))
		return 1;

	if (eatToken(tokens, '!', pos, nbNode))
		return 1;

	return 0;
}

int cast_expression(Token **tokens, int *pos, int nbNode)
{
	if (unary_expression(tokens, pos, nbNode))
		return 1;

	if (eatToken(tokens, OpenPar, pos, nbNode))
		if (type_name(tokens, pos, nbNode))
			if (eatToken(tokens, ClosedPar, pos, nbNode))
				return cast_expression(tokens, pos, nbNode);

	return 0;
}

int multiplicative_expression(Token **tokens, int *pos, int nbNode)
{
	if (cast_expression(tokens, pos, nbNode))
		return 1;

	if (multiplicative_expression(tokens, pos, nbNode))
	{
		if (eatToken(tokens, '*', pos, nbNode))
			return cast_expression(tokens, pos, nbNode);
		if (eatToken(tokens, '/', pos, nbNode))
			return cast_expression(tokens, pos, nbNode);
		if (eatToken(tokens, '%', pos, nbNode))
			return cast_expression(tokens, pos, nbNode);
	}
	return 0;
}

int additive_expression(Token **tokens, int *pos, int nbNode)
{
	if (multiplicative_expression(tokens, pos, nbNode))
		return 1;

	if (additive_expression(tokens, pos, nbNode))
	{
		if (eatToken(tokens, '+', pos, nbNode))
			return multiplicative_expression(tokens, pos, nbNode);
		if (eatToken(tokens, '-', pos, nbNode))
			return multiplicative_expression(tokens, pos, nbNode);
	}
	return 0;
}

int shift_expression(Token **tokens, int *pos, int nbNode)
{
	if (additive_expression(tokens, pos, nbNode))
		return 1;

	if (shift_expression(tokens, pos, nbNode))
	{
		if (eatToken(tokens, LEFT_OP, pos, nbNode))
			return additive_expression(tokens, pos, nbNode);
		if (eatToken(tokens, RIGHT_OP, pos, nbNode))
			return additive_expression(tokens, pos, nbNode);
	}
	return 0;
}

int relational_expression(Token **tokens, int *pos, int nbNode)
{
	if (shift_expression(tokens, pos, nbNode))
		return 1;

	if (relational_expression(tokens, pos, nbNode))
	{
		if (eatToken(tokens, '<', pos, nbNode))
			return shift_expression(tokens, pos, nbNode);
		if (eatToken(tokens, '>', pos, nbNode))
			return shift_expression(tokens, pos, nbNode);
		if (eatToken(tokens, LE_OP, pos, nbNode))
			return shift_expression(tokens, pos, nbNode);
		if (eatToken(tokens, GE_OP, pos, nbNode))
			return shift_expression(tokens, pos, nbNode);
	}
	return 0;
}

int equality_expression(Token **tokens, int *pos, int nbNode)
{
	if (relational_expression(tokens, pos, nbNode))
		return 1;

	if (equality_expression(tokens, pos, nbNode))
	{
		if (eatToken(tokens, EQ_OP, pos, nbNode))
			return relational_expression(tokens, pos, nbNode);
		if (eatToken(tokens, NE_OP, pos, nbNode))
			return relational_expression(tokens, pos, nbNode);
	}
	return 0;
}

int and_expression(Token **tokens, int *pos, int nbNode)
{
	if (equality_expression(tokens, pos, nbNode))
		return 1;

	if (and_expression(tokens, pos, nbNode))
		if (eatToken(tokens, '&', pos, nbNode))
			return equality_expression(tokens, pos, nbNode);

	return 0;
}

int exclusive_or_expression(Token **tokens, int *pos, int nbNode)
{
	if (and_expression(tokens, pos, nbNode))
		return 1;

	if (exclusive_or_expression(tokens, pos, nbNode))
		if (eatToken(tokens, '^', pos, nbNode))
			return and_expression(tokens, pos, nbNode);

	return 0;
}

int inclusive_or_expression(Token **tokens, int *pos, int nbNode)
{
	if (exclusive_or_expression(tokens, pos, nbNode))
		return 1;

	if (inclusive_or_expression(tokens, pos, nbNode))
		if (eatToken(tokens, '|', pos, nbNode))
			return exclusive_or_expression(tokens, pos, nbNode);

	return 0;
}

int logical_and_expression(Token **tokens, int *pos, int nbNode)
{
	if (inclusive_or_expression(tokens, pos, nbNode))
		return 1;

	if (logical_and_expression(tokens, pos, nbNode))
		if (eatToken(tokens, AND_OP, pos, nbNode))
			return inclusive_or_expression(tokens, pos, nbNode);

	return 0;
}

int logical_or_expression(Token **tokens, int *pos, int nbNode)
{
	if (logical_and_expression(tokens, pos, nbNode))
		return 1;

	if (logical_or_expression(tokens, pos, nbNode))
		if (eatToken(tokens, OR_OP, pos, nbNode))
			return logical_and_expression(tokens, pos, nbNode);

	return 0;
}

int conditional_expression(Token **tokens, int *pos, int nbNode)
{
	if (logical_or_expression(tokens, pos, nbNode))
		return 1;

	if (logical_or_expression(tokens, pos, nbNode))
		if (eatToken(tokens, '?', pos, nbNode))
			if (expression(tokens, pos, nbNode))
				if (eatToken(tokens, ':', pos, nbNode))
					return conditional_expression(tokens, pos, nbNode);
	return 0;
}

int assignment_expression(Token **tokens, int *pos, int nbNode)
{
	if (conditional_expression(tokens, pos, nbNode))
		return 1;

	if (unary_expression(tokens, pos, nbNode))
		if (assignment_operator(tokens, pos, nbNode))
			return assignment_expression(tokens, pos, nbNode);

	return 0;
}

int assignment_operator(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, '=', pos, nbNode))
		return 1;

	if (eatToken(tokens, MUL_ASSIGN, pos, nbNode))
		return 1;

	if (eatToken(tokens, DIV_ASSIGN, pos, nbNode))
		return 1;

	if (eatToken(tokens, MOD_ASSIGN, pos, nbNode))
		return 1;

	if (eatToken(tokens, ADD_ASSIGN, pos, nbNode))
		return 1;

	if (eatToken(tokens, SUB_ASSIGN, pos, nbNode))
		return 1;

	if (eatToken(tokens, LEFT_ASSIGN, pos, nbNode))
		return 1;

	if (eatToken(tokens, RIGHT_ASSIGN, pos, nbNode))
		return 1;

	if (eatToken(tokens, AND_ASSIGN, pos, nbNode))
		return 1;

	if (eatToken(tokens, XOR_ASSIGN, pos, nbNode))
		return 1;

	if (eatToken(tokens, OR_ASSIGN, pos, nbNode))
		return 1;

	return 0;
}

int expression(Token **tokens, int *pos, int nbNode)
{
	if (assignment_expression(tokens, pos, nbNode))
		return 1;

	if (expression(tokens, pos, nbNode))
		if (eatToken(tokens, COMA, pos, nbNode))
			return assignment_expression(tokens, pos, nbNode);
	return 0;
}

int constant_expression(Token **tokens, int *pos, int nbNode)
{
	return conditional_expression(tokens, pos, nbNode);
}

int declaration(Token **tokens, int *pos, int nbNode)
{
	if (declaration_specifiers(tokens, pos, nbNode))
	{
		if (eatToken(tokens, ';', pos, nbNode))
			return 1;

		if (init_declarator_list(tokens, pos, nbNode))
			return eatToken(tokens, ';', pos, nbNode);
	}
	return 0;
}

int declaration_specifiers(Token **tokens, int *pos, int nbNode)
{
	// J'ai inversé ici
	if (storage_class_specifier(tokens, pos, nbNode))
	{
		if (declaration_specifiers(tokens, pos, nbNode))
			return 1;
		return 1;
	}
	if (type_specifier(tokens, pos, nbNode))
	{
		if (declaration_specifiers(tokens, pos, nbNode))
			return 1;
		return 1;
	}
	if (type_qualifier(tokens, pos, nbNode))
	{
		if (declaration_specifiers(tokens, pos, nbNode))
			return 1;
		return 1;
	}
	return 0;
}

int init_declarator_list(Token **tokens, int *pos, int nbNode)
{
	if (init_declarator(tokens, pos, nbNode))
		return 1;

	if (init_declarator_list(tokens, pos, nbNode))
		if (eatToken(tokens, COMA, pos, nbNode))
			return init_declarator(tokens, pos, nbNode);

	return 0;
}

int init_declarator(Token **tokens, int *pos, int nbNode)
{
	if (declarator(tokens, pos, nbNode))
	{
		if (eatToken(tokens, '=', pos, nbNode))
			return initializer(tokens, pos, nbNode);
		return 1;
	}
	return 0;
}

int storage_class_specifier(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, TYPEDEF, pos, nbNode))
		return 1;

	if (eatToken(tokens, EXTERN, pos, nbNode))
		return 1;

	if (eatToken(tokens, STATIC, pos, nbNode))
		return 1;

	if (eatToken(tokens, AUTO, pos, nbNode))
		return 1;

	if (eatToken(tokens, REGISTER, pos, nbNode))
		return 1;

	return 0;
}

int type_specifier(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, VOID, pos, nbNode))
		return 1;

	if (eatToken(tokens, CHAR, pos, nbNode))
		return 1;

	if (eatToken(tokens, SHORT, pos, nbNode))
		return 1;

	if (eatToken(tokens, INT, pos, nbNode))
		return 1;

	if (eatToken(tokens, LONG, pos, nbNode))
		return 1;

	if (eatToken(tokens, FLOAT, pos, nbNode))
		return 1;

	if (eatToken(tokens, DOUBLE, pos, nbNode))
		return 1;

	if (eatToken(tokens, SIGNED, pos, nbNode))
		return 1;

	if (eatToken(tokens, UNSIGNED, pos, nbNode))
		return 1;

	if (struct_or_union_specifier(tokens, pos, nbNode))
		return 1;

	if (enum_specifier(tokens, pos, nbNode))
		return 1;

	if (eatToken(tokens, TYPE_NAME, pos, nbNode))
		return 1;

	return 0;
}

int struct_or_union_specifier(Token **tokens, int *pos, int nbNode)
{
	if (struct_or_union(tokens, pos, nbNode))
	{
		if (eatToken(tokens, IDENTIFIER, pos, nbNode))
		{
			if (eatToken(tokens, '{', pos, nbNode))
				if (struct_declaration_list(tokens, pos, nbNode))
					return eatToken(tokens, '}', pos, nbNode);
			return 1;
		}

		if (eatToken(tokens, '{', pos, nbNode))
			if (struct_declaration_list(tokens, pos, nbNode))
				return eatToken(tokens, '}', pos, nbNode);
	}
	return 0;
}

int struct_or_union(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, STRUCT, pos, nbNode))
		return 1;

	if (eatToken(tokens, UNION, pos, nbNode))
		return 1;

	return 0;
}

int struct_declaration_list(Token **tokens, int *pos, int nbNode)
{
	if (struct_declaration(tokens, pos, nbNode))
		return 1;

	if (struct_declaration_list(tokens, pos, nbNode))
		return struct_declaration(tokens, pos, nbNode);

	return 0;
}

int struct_declaration(Token **tokens, int *pos, int nbNode)
{
	if (specifier_qualifier_list(tokens, pos, nbNode))
		if (struct_declarator_list(tokens, pos, nbNode))
			return eatToken(tokens, ';', pos, nbNode);

	return 0;
}

int specifier_qualifier_list(Token **tokens, int *pos, int nbNode)
{
	if (type_specifier(tokens, pos, nbNode))
	{
		if (specifier_qualifier_list(tokens, pos, nbNode))
			return 1;
		return 1;
	}

	if (type_qualifier(tokens, pos, nbNode))
	{
		if (specifier_qualifier_list(tokens, pos, nbNode))
			return 1;
		return 1;
	}
	return 0;
}

int struct_declarator_list(Token **tokens, int *pos, int nbNode)
{
	if (struct_declarator(tokens, pos, nbNode))
		return 1;

	if (struct_declarator_list(tokens, pos, nbNode))
		if (eatToken(tokens, COMA, pos, nbNode))
			return struct_declarator(tokens, pos, nbNode);

	return 0;
}

int struct_declarator(Token **tokens, int *pos, int nbNode)
{
	if (declarator(tokens, pos, nbNode))
		return 1;

	if (eatToken(tokens, ':', pos, nbNode))
		return constant_expression(tokens, pos, nbNode);

	if (declarator(tokens, pos, nbNode))
		if (eatToken(tokens, ':', pos, nbNode))
			return constant_expression(tokens, pos, nbNode);

	return 0;
}

int enum_specifier(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, ENUM, pos, nbNode))
	{
		if (eatToken(tokens, '{', pos, nbNode))
		{
			if (enumerator_list(tokens, pos, nbNode))
				return eatToken(tokens, '}', pos, nbNode);
			return 0;
		}
		if (eatToken(tokens, IDENTIFIER, pos, nbNode))
		{
			if (eatToken(tokens, '{', pos, nbNode))
				if (enumerator_list(tokens, pos, nbNode))
					return eatToken(tokens, '}', pos, nbNode);
			return 1;
		}
	}
	return 0;
}

int enumerator_list(Token **tokens, int *pos, int nbNode)
{
	if (enumerator(tokens, pos, nbNode))
		return 1;

	if (enumerator_list(tokens, pos, nbNode))
		if (eatToken(tokens, COMA, pos, nbNode))
			return enumerator(tokens, pos, nbNode);

	return 0;
}

int enumerator(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, IDENTIFIER, pos, nbNode))
	{
		if (eatToken(tokens, '=', pos, nbNode))
			return constant_expression(tokens, pos, nbNode);
		return 1;
	}
	return 0;
}

int type_qualifier(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, CONST, pos, nbNode))
		return 1;

	if (eatToken(tokens, VOLATILE, pos, nbNode))
		return 1;
	return 0;
}

int declarator(Token **tokens, int *pos, int nbNode)
{
	if (pointer(tokens, pos, nbNode))
		return direct_declarator(tokens, pos, nbNode);
	return direct_declarator(tokens, pos, nbNode);
}

int direct_declarator(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, IDENTIFIER, pos, nbNode))
		return 1;

	if (eatToken(tokens, OpenPar, pos, nbNode))
	{
		if (declarator(tokens, pos, nbNode))
			return eatToken(tokens, ClosedPar, pos, nbNode);
		return 0;
	}

	if (direct_declarator(tokens, pos, nbNode))
	{
		if (eatToken(tokens, '[', pos, nbNode))
		{
			if (constant_expression(tokens, pos, nbNode))
				return eatToken(tokens, ']', pos, nbNode);
			return eatToken(tokens, ']', pos, nbNode);
		}

		if (eatToken(tokens, OpenPar, pos, nbNode))
		{
			if (parameter_type_list(tokens, pos, nbNode))
				return eatToken(tokens, ClosedPar, pos, nbNode);

			if (identifier_list(tokens, pos, nbNode))
				return eatToken(tokens, ClosedPar, pos, nbNode);

			return eatToken(tokens, ClosedPar, pos, nbNode);
		}
	}
	return 0;
}

int pointer(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, '*', pos, nbNode))
	{
		if (type_qualifier_list(tokens, pos, nbNode))
			return 1;
		if (pointer(tokens, pos, nbNode))
			return 1;
		if (type_qualifier_list(tokens, pos, nbNode))
			return pointer(tokens, pos, nbNode);
		return 1;
	}
	return 0;
}

int type_qualifier_list(Token **tokens, int *pos, int nbNode)
{
	if (type_qualifier(tokens, pos, nbNode))
		return 1;

	if (type_qualifier_list(tokens, pos, nbNode))
		return type_qualifier(tokens, pos, nbNode);

	return 0;
}

int parameter_type_list(Token **tokens, int *pos, int nbNode)
{
	if (parameter_list(tokens, pos, nbNode))
	{
		if (eatToken(tokens, COMA, pos, nbNode))
			return eatToken(tokens, ELLIPSIS, pos, nbNode);
		return 1;
	}
	return 0;
}

int parameter_list(Token **tokens, int *pos, int nbNode)
{
	if (parameter_declaration(tokens, pos, nbNode))
		return 1;

	if (parameter_list(tokens, pos, nbNode))
		if (eatToken(tokens, COMA, pos, nbNode))
			return parameter_declaration(tokens, pos, nbNode);

	return 0;
}

int parameter_declaration(Token **tokens, int *pos, int nbNode)
{
	if (declaration_specifiers(tokens, pos, nbNode))
	{
		if (declarator(tokens, pos, nbNode))
			return 1;

		if (abstract_declarator(tokens, pos, nbNode))
			return 1;
		return 1;
	}
	return 0;
}

int identifier_list(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, IDENTIFIER, pos, nbNode))
		return 1;

	if (identifier_list(tokens, pos, nbNode))
		if (eatToken(tokens, COMA, pos, nbNode))
			return eatToken(tokens, IDENTIFIER, pos, nbNode);

	return 0;
}

int type_name(Token **tokens, int *pos, int nbNode)
{
	if (specifier_qualifier_list(tokens, pos, nbNode))
	{
		if (abstract_declarator(tokens, pos, nbNode))
			return 1;
		return 1;
	}
	return 0;
}

int abstract_declarator(Token **tokens, int *pos, int nbNode)
{
	if (direct_abstract_declarator(tokens, pos, nbNode))
		return 1;

	if (pointer(tokens, pos, nbNode))
	{
		if (direct_abstract_declarator(tokens, pos, nbNode))
			return 1;
		return 1;
	}
	return 0;
}

int direct_abstract_declarator(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, OpenPar, pos, nbNode))
	{
		if (abstract_declarator(tokens, pos, nbNode))
			return eatToken(tokens, ClosedPar, pos, nbNode);
		return 0;
	}

	if (eatToken(tokens, '[', pos, nbNode))
	{
		if (eatToken(tokens, ']', pos, nbNode))
			return 1;
		if (constant_expression(tokens, pos, nbNode))
			if (eatToken(tokens, ']', pos, nbNode))
				return 1;
		return 0;
	}

	if (direct_abstract_declarator(tokens, pos, nbNode))
	{
		if (eatToken(tokens, '[', pos, nbNode))
		{
			if (eatToken(tokens, ']', pos, nbNode))
				return 1;
			if (constant_expression(tokens, pos, nbNode))
				if (eatToken(tokens, ']', pos, nbNode))
					return 1;
		}
		return 0;
	}

	if (eatToken(tokens, OpenPar, pos, nbNode))
	{
		if (eatToken(tokens, ClosedPar, pos, nbNode))
			return 1;
		if (parameter_type_list(tokens, pos, nbNode))
			return eatToken(tokens, ClosedPar, pos, nbNode);
		return 0;
	}

	if (direct_abstract_declarator(tokens, pos, nbNode))
	{
		if (eatToken(tokens, OpenPar, pos, nbNode))
			return eatToken(tokens, ClosedPar, pos, nbNode);

		if (parameter_type_list(tokens, pos, nbNode))
			return eatToken(tokens, ClosedPar, pos, nbNode);
	}
	return 0;
}

int initializer(Token **tokens, int *pos, int nbNode)
{
	if (assignment_expression(tokens, pos, nbNode))
		return 1;

	if (eatToken(tokens, '{', pos, nbNode))
		if (initializer_list(tokens, pos, nbNode))
		{
			if (eatToken(tokens, '}', pos, nbNode))
				return 1;
			if (eatToken(tokens, COMA, pos, nbNode))
				return eatToken(tokens, '}', pos, nbNode);
		}

	return 0;
}

int initializer_list(Token **tokens, int *pos, int nbNode)
{
	if (initializer(tokens, pos, nbNode))
		return 1;

	if (initializer_list(tokens, pos, nbNode))
		if (eatToken(tokens, COMA, pos, nbNode))
			return initializer(tokens, pos, nbNode);

	return 0;
}

int statement(Token **tokens, int *pos, int nbNode)
{
	if (labeled_statement(tokens, pos, nbNode))
		return 1;
	if (compound_statement(tokens, pos, nbNode))
		return 1;
	if (expression_statement(tokens, pos, nbNode))
		return 1;
	if (selection_statement(tokens, pos, nbNode))
		return 1;
	if (iteration_statement(tokens, pos, nbNode))
		return 1;
	if (jump_statement(tokens, pos, nbNode))
		return 1;
	return 0;
}

int labeled_statement(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, IDENTIFIER, pos, nbNode))
	{
		if (eatToken(tokens, ':', pos, nbNode))
			return statement(tokens, pos, nbNode);
		return 0;
	}

	if (eatToken(tokens, CASE, pos, nbNode))
	{
		if (constant_expression(tokens, pos, nbNode))
			if (eatToken(tokens, ':', pos, nbNode))
				return statement(tokens, pos, nbNode);
		return 0;
	}

	if (eatToken(tokens, DEFAULT, pos, nbNode))
		if (eatToken(tokens, ':', pos, nbNode))
			return statement(tokens, pos, nbNode);

	return 0;
}

int compound_statement(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, '{', pos, nbNode))
	{
		if (eatToken(tokens, '}', pos, nbNode))
			return 1;
		if (statement_list(tokens, pos, nbNode))
			return eatToken(tokens, '}', pos, nbNode);
		if (declaration_list(tokens, pos, nbNode))
			if (eatToken(tokens, '}', pos, nbNode))
				return 1;
		if (statement_list(tokens, pos, nbNode))
			return eatToken(tokens, '}', pos, nbNode);
	}
	return 0;
}

int declaration_list(Token **tokens, int *pos, int nbNode)
{
	if (declaration(tokens, pos, nbNode))
		return 1;

	if (declaration_list(tokens, pos, nbNode))
		return declaration(tokens, pos, nbNode);

	return 0;
}

int statement_list(Token **tokens, int *pos, int nbNode)
{
	if (statement(tokens, pos, nbNode))
		return 1;
	if (statement_list(tokens, pos, nbNode))
		return statement(tokens, pos, nbNode);

	return 0;
}

int expression_statement(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, ';', pos, nbNode))
		return 1;

	if (expression(tokens, pos, nbNode))
		return eatToken(tokens, ';', pos, nbNode);

	return 0;
}

int selection_statement(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, IF, pos, nbNode))
	{
		if (eatToken(tokens, OpenPar, pos, nbNode))
			if (expression(tokens, pos, nbNode))
				if (eatToken(tokens, ClosedPar, pos, nbNode))
					if (statement(tokens, pos, nbNode))
					{
						if (eatToken(tokens, ELSE, pos, nbNode))
							return statement(tokens, pos, nbNode);
						return 1;
					}
		return 0;
	}

	if (eatToken(tokens, SWITCH, pos, nbNode))
		if (eatToken(tokens, OpenPar, pos, nbNode))
			if (expression(tokens, pos, nbNode))
				if (eatToken(tokens, ClosedPar, pos, nbNode))
					return statement(tokens, pos, nbNode);

	return 0;
}

int iteration_statement(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, WHILE, pos, nbNode))
		if (eatToken(tokens, OpenPar, pos, nbNode))
			if (expression(tokens, pos, nbNode))
				if (eatToken(tokens, ClosedPar, pos, nbNode))
					return statement(tokens, pos, nbNode);

	if (eatToken(tokens, DO, pos, nbNode))
		if (statement(tokens, pos, nbNode))
			if (eatToken(tokens, WHILE, pos, nbNode))
				if (eatToken(tokens, OpenPar, pos, nbNode))
					if (expression(tokens, pos, nbNode))
						if (eatToken(tokens, ClosedPar, pos, nbNode))
							return eatToken(tokens, ';', pos, nbNode);

	if (eatToken(tokens, FOR, pos, nbNode))
		if (eatToken(tokens, OpenPar, pos, nbNode))
			if (expression_statement(tokens, pos, nbNode))
				if (expression_statement(tokens, pos, nbNode))
				{
					if (eatToken(tokens, ClosedPar, pos, nbNode))
						return statement(tokens, pos, nbNode);
					if (expression(tokens, pos, nbNode))
						if (eatToken(tokens, ClosedPar, pos, nbNode))
							return statement(tokens, pos, nbNode);
				}

	return 0;
}

int jump_statement(Token **tokens, int *pos, int nbNode)
{
	if (eatToken(tokens, GOTO, pos, nbNode))
	{
		if (eatToken(tokens, IDENTIFIER, pos, nbNode))
			return eatToken(tokens, ';', pos, nbNode);
		return 0;
	}

	if (eatToken(tokens, CONTINUE, pos, nbNode))
		return eatToken(tokens, ';', pos, nbNode);

	if (eatToken(tokens, BREAK, pos, nbNode))
		return eatToken(tokens, ';', pos, nbNode);

	if (eatToken(tokens, RETURN, pos, nbNode))
	{
		if (eatToken(tokens, ';', pos, nbNode))
			return 1;
		if (expression(tokens, pos, nbNode))
			return eatToken(tokens, ';', pos, nbNode);
		return 0;
	}

	return 0;
}

int translation_unit(Token **tokens, int *pos, int nbNode)
{
	if (external_declaration(tokens, pos, nbNode))
		return 1;

	if (translation_unit(tokens, pos, nbNode))
		return external_declaration(tokens, pos, nbNode);

	return 0;
}

int external_declaration(Token **tokens, int *pos, int nbNode)
{
	if (function_definition(tokens, pos, nbNode))
		return 1;

	if (declaration(tokens, pos, nbNode))
		return 1;

	return 0;
}

int function_definition(Token **tokens, int *pos, int nbNode)
{
	if (declaration_specifiers(tokens, pos, nbNode))
		if (declarator(tokens, pos, nbNode))
		{
			if (declaration_list(tokens, pos, nbNode))
				return compound_statement(tokens, pos, nbNode);
			return compound_statement(tokens, pos, nbNode);
		}

	if (declarator(tokens, pos, nbNode))
	{
		if (declaration_list(tokens, pos, nbNode))
			return compound_statement(tokens, pos, nbNode);
		return compound_statement(tokens, pos, nbNode);
	}
	return 0;
}


void check(Token **tokens, int nbNode)
{

	for (int i = 0; i < nbNode; i++)
		printf("%s", tokens[i]->value);
	printf("\n");
	int pos = 0;
	if (translation_unit(tokens, &pos, nbNode))
		printf("Failed\n");
	else
		printf("Good\n");
	printf("test\n");
}