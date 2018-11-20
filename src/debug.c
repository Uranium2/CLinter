//
// Created by Théo Huchard on 20/11/2018.
//
#include "debug.h"

void debug_config(Config * r) {
    printf(
            "extends : %s \n"
            "arrayBracketEol : %c \n"
            "operatorsSpacing : %c \n"
            "commaSpacing : %c \n"
            "indent : %c \n"
            "commentsHeader : %c \n"
            "maxLineNumbers : %c \n"
            "maxFileLineNumbers : %c \n"
            "noTrallingSpaces : %c \n"
            "NoMultiDeclaration : %c \n"
            "unusedVariable : %c \n"
            "undeclaredVariable : %c \n"
            "noPrototype : %c \n"
            "unusedFunction : %c \n"
            "undeclaredFunction : %c \n"
            "variableAssignmentType : %c \n"
            "functionParametersType : %c \n"
            "recursive : %c \n"
            "nbExcludedFiles : %c \n",
            r->extends,
            r->arrayBracketEol,
            r->operatorsSpacing,
            r->commaSpacing,
            r->indent,
            r->commentsHeader,
            r->maxLineNumbers,
            r->maxFileLineNumbers,
            r->noTrallingSpaces,
            r->NoMultiDeclaration,
            r->unusedVariable,
            r->undeclaredVariable,
            r->noPrototype,
            r->unusedFunction,
            r->undeclaredFunction,
            r->variableAssignmentType,
            r->functionParametersType,
            r->recursive,
            r->nbExcludedFiles
    );
}