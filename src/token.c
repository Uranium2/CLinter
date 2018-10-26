#include "token.h"

char *getEnumName(Type type)
{

        switch (type)
        {
        case Operator:
                return "Operator";
                break;
        case Delimiter:
                return "Delimiter";
                break;
        case Variable:
                return "Variable";
                break;
        case Numerical:
                return "Numerical";
                break;
        case KeyWord:
                return "KeyWord";
                break;

        // new
        case IDENTIFIER:
                return "IDENTIFIER";
                break;
        case CONSTANT:
                return "CONSTANT";
                break;
        case STRING_LITERAL:
                return "STRING_LITERAL";
                break;
        case PTR_OP:
                return "PTR_OP";
                break;
        case INC_OP:
                return "INC_OP";
                break;
        case DEC_OP:
                return "DEC_OP";
                break;
        case SIZEOF:
                return "SIZEOF";
                break;
        case LEFT_OP:
                return "LEFT_OP";
                break;
        case RIGHT_OP:
                return "RIGHT_OP";
                break;
        case LE_OP:
                return "LE_OP";
                break;
        case GE_OP:
                return "GE_OP";
                break;
        case EQ_OP:
                return "EQ_OP";
                break;
        case NE_OP:
                return "NE_OP";
                break;
        case AND_OP:
                return "AND_OP";
                break;
        case OR_OP:
                return "OR_OP";
                break;
        case MUL_ASSIGN:
                return "MUL_ASSIGN";
                break;
        case DIV_ASSIGN:
                return "DIV_ASSIGN";
                break;
        case MOD_ASSIGN:
                return "MOD_ASSIGN";
                break;
        case ADD_ASSIGN:
                return "ADD_ASSIGN";
                break;
        case SUB_ASSIGN:
                return "SUB_ASSIGN";
                break;
        case LEFT_ASSIGN:
                return "LEFT_ASSIGN";
                break;
        case RIGHT_ASSIGN:
                return "RIGHT_ASSIGN";
                break;
        case AND_ASSIGN:
                return "AND_ASSIGN";
                break;
        case XOR_ASSIGN:
                return "XOR_ASSIGN";
                break;
        case OR_ASSIGN:
                return "OR_ASSIGN";
                break;
        case TYPEDEF:
                return "TYPEDEF";
                break;
        case EXTERN:
                return "EXTERN";
                break;
        case STATIC:
                return "STATIC";
                break;
        case AUTO:
                return "AUTO";
                break;
        case REGISTER:
                return "REGISTER";
                break;
        case VOID:
                return "VOID";
                break;
        case CHAR:
                return "CHAR";
                break;
        case SHORT:
                return "SHORT";
                break;
        case INT:
                return "INT";
                break;
        case LONG:
                return "LONG";
                break;
        case FLOAT:
                return "FLOAT";
                break;
        case DOUBLE:
                return "DOUBLE";
                break;
        case SIGNED:
                return "SIGNED";
                break;
        case UNSIGNED:
                return "UNSIGNED";
                break;
        case TYPE_NAME:
                return "TYPE_NAME";
                break;
        case STRUCT:
                return "STRUCT";
                break;
        case UNION:
                return "UNION";
                break;
        case ENUM:
                return "ENUM";
                break;
        case CONST:
                return "CONST";
                break;
        case VOLATILE:
                return "VOLATILE";
                break;
        case ELLIPSIS:
                return "ELLIPSIS";
                break;
        case CASE:
                return "CASE";
                break;
        case DEFAULT:
                return "DEFAULT";
                break;
        case IF:
                return "IF";
                break;
        case ELSE:
                return "ELSE";
                break;
        case SWITCH:
                return "SWITCH";
                break;
        case WHILE:
                return "WHILE";
                break;
        case DO:
                return "DO";
                break;
        case FOR:
                return "FOR";
                break;
        case GOTO:
                return "GOTO";
                break;
        case CONTINUE:
                return "CONTINUE";
                break;
        case BREAK:
                return "BREAK";
                break;
        case RETURN:
                return "RETURN";
                break;
        case SPACE:
                return "SPACE";
                break;
        case TAB:
                return "TAB";
                break;
        default:
                return "Nothing";
                break;
        }
        return "Nothing";
}

Token *createToken(Type type, char *value)
{
        Token *token = malloc(sizeof(Token));
        token->type = type;
        token->value = value;
        return token;
}
