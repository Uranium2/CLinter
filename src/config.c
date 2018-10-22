#include "config.h"

int isValidConfFile(char *filename)
{
    char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return 0;

    if (strcmp(dot, "lconf"))
        return 1;
    return 0;
}

int getVal(char **file, char *rule, int nbLines)
{
    
    for(int i = 0; i < nbLines; i++)
    {
        if (strstr(file[i], rule) != NULL) {
            char *p = strrchr(file[i], ' ');
            if (p && *(p + 1)) {
                if (strcmp(p + 1, "on") == 0)
                    return 1;
                if (strcmp(p + 1, "off") == 0)
                    return 0;
                return atoi(p + 1);
            }
        }
    }
    return 0;
}

Config *loadConfig(char *path)
{
    char **configText;
    int nbLines = 0;
    if (!isValidConfFile(path))
       configText = getAllLines("default.lconf", &nbLines);
    else
        configText = getAllLines(path, &nbLines);

    Config *conf = malloc(sizeof(Config));
    conf->extends = 0;
    conf->arrayBracketEol = getVal(configText, "array-bracket-eol", nbLines);
    conf->operatorsSpacing = getVal(configText, "operators-spacing", nbLines);
    conf->commaSpacing = getVal(configText, "comma-spacing", nbLines);
    conf->indent = getVal(configText, "indent", nbLines); // nb space of indend
    conf->commentsHeader = getVal(configText, "comments-header", nbLines);
    conf->maxLineNumbers = getVal(configText, "max-line-numbers", nbLines); // nb Max char per line
    conf->maxFileLineNumbers = getVal(configText, "max-file-line-numbers", nbLines); // nb Max line per file
    conf->noTrallingSpaces = getVal(configText, "no-tralling-spaces", nbLines);
    conf->NoMultiDeclaration = getVal(configText, "no-multi-declaration", nbLines);
    conf->unusedVariable = getVal(configText, "unused-variable", nbLines);
    conf->undeclaredVariable = getVal(configText, "undeclared-variable", nbLines);
    conf->noPrototype = getVal(configText, "no-prototype", nbLines);
    conf->unusedFunction = getVal(configText, "unused-function", nbLines);
    conf->undeclaredFunction = getVal(configText, "undeclared-function", nbLines);
    conf->variableAssignmentType = getVal(configText, "variable-assignment-type", nbLines);
    conf->functionParametersType = getVal(configText, "function-parameters-type", nbLines);
    conf->excludedFiles = NULL;
    conf->nbExcludedFiles = 0;
    conf->recursive = 0;
    return conf;
}