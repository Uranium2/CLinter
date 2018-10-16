#include "ast.h"

AstNode* createNode(int type, char* value) {
        AstNode* node = malloc(sizeof(AstNode));
        node->type = type;
        node->value = value;
        return node;
}
