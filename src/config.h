#ifndef CONFIG
#define CONFIG

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct Config_t
{
    char *extends;
    short arrayBracketEol;
    short operatorsSpacing;
    short commaSpacing;
    short indent; // nb space of indend
    short commentsHeader;
    short maxLineNumbers; // nb Max char per line
    short maxFileLineNumbers; // nb Max line per file
    short noTrallingSpaces;
    short NoMultiDeclaration;
    short unusedVariable;
    short undeclaredVariable;
    short noPrototype;
    short unusedFunction;
    short undeclaredFunction;
    short variableAssignmentType;
    short functionParametersType;
    char **excludedFiles;
    int nbExcludedFiles;
    short recursive;
} Config;

// Reads a file and loads the configuration
Config *loadConfig(char *path);

char* getConfigFile(int argc, char** argv);

#endif
