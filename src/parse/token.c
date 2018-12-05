/**
* @file token.c
* @brief This c file will contain all functions to create a Token.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#include "token.h"

/**
 * @brief Get the Enum Name of a Type
 * 
 * @param type Given Type
 * @return char* Type cast to string
 */
char *getEnumName(Type type) {
    switch (type) {
        case DotComa:
            return "DotComa";
        case OpenBracket:
            return "OpenBracket";
        case ClosedBracket:
            return "ClosedBracket";
        case COMA:
            return "COMA";
        case OpenPar:
            return "OpenPar";
        case ClosedPar:
            return "ClosedPar";
        case Operator:
            return "Operator";
        case Delimiter:
            return "Delimiter";
        case Variable:
            return "Variable";
        case Numerical:
            return "Numerical";
        case KeyWord:
            return "KeyWord";
        case Comment:
            return "Comment";
            // new
        case IDENTIFIER:
            return "IDENTIFIER";
        case CONSTANT:
            return "CONSTANT";
        case STRING_LITERAL:
            return "STRING_LITERAL";
        case PTR_OP:
            return "PTR_OP";
        case INC_OP:
            return "INC_OP";
        case DEC_OP:
            return "DEC_OP";
        case SIZEOF:
            return "SIZEOF";
        case LEFT_OP:
            return "LEFT_OP";
        case RIGHT_OP:
            return "RIGHT_OP";
        case LE_OP:
            return "LE_OP";
        case GE_OP:
            return "GE_OP";
        case EQ_OP:
            return "EQ_OP";
        case NE_OP:
            return "NE_OP";
        case AND_OP:
            return "AND_OP";
        case OR_OP:
            return "OR_OP";
        case MUL_ASSIGN:
            return "MUL_ASSIGN";
        case DIV_ASSIGN:
            return "DIV_ASSIGN";
        case MOD_ASSIGN:
            return "MOD_ASSIGN";
        case ADD_ASSIGN:
            return "ADD_ASSIGN";
        case SUB_ASSIGN:
            return "SUB_ASSIGN";
        case LEFT_ASSIGN:
            return "LEFT_ASSIGN";
        case RIGHT_ASSIGN:
            return "RIGHT_ASSIGN";
        case AND_ASSIGN:
            return "AND_ASSIGN";
        case XOR_ASSIGN:
            return "XOR_ASSIGN";
        case OR_ASSIGN:
            return "OR_ASSIGN";
        case TYPEDEF:
            return "TYPEDEF";
        case EXTERN:
            return "EXTERN";
        case STATIC:
            return "STATIC";
        case AUTO:
            return "AUTO";
        case REGISTER:
            return "REGISTER";
        case VOID:
            return "VOID";
        case CHAR:
            return "CHAR";
        case SHORT:
            return "SHORT";
        case INT:
            return "INT";
        case LONG:
            return "LONG";
        case FLOAT:
            return "FLOAT";
        case DOUBLE:
            return "DOUBLE";
        case SIGNED:
            return "SIGNED";
        case UNSIGNED:
            return "UNSIGNED";
        case TYPE_NAME:
            return "TYPE_NAME";
        case STRUCT:
            return "STRUCT";
        case UNION:
            return "UNION";
        case ENUM:
            return "ENUM";
        case CONST:
            return "CONST";
        case VOLATILE:
            return "VOLATILE";
        case ELLIPSIS:
            return "ELLIPSIS";
        case CASE:
            return "CASE";
        case DEFAULT:
            return "DEFAULT";
        case IF:
            return "IF";
        case ELSE:
            return "ELSE";
        case SWITCH:
            return "SWITCH";
        case WHILE:
            return "WHILE";
        case DO:
            return "DO";
        case FOR:
            return "FOR";
        case GOTO:
            return "GOTO";
        case CONTINUE:
            return "CONTINUE";
        case BREAK:
            return "BREAK";
        case RETURN:
            return "RETURN";
        case SPACE:
            return "SPACE";
        case TAB:
            return "TAB";
        default:
            return "Nothing";
    }
    return "Nothing";
}

/**
 * @brief Create a Token structure
 * 
 * @param type Given Type
 * @param value Given String value
 * @param pos Given position of the Token in a line 
 * @return Token* A new Token
 */
Token *createToken(Type type, char *value, int pos) {
    Token *token = malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    token->pos = pos;
    return token;
}
