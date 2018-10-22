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

char *getExtends(char **file, int nbLines)
{
    
    for(int i = 0; i < nbLines - 1; i++)
    {
        if (strstr(file[i], "extends") != NULL) {
            char* res = malloc(sizeof(char) * strlen(file[i + 1]));
            res = file[i + 1];
            return res;
        }
    }
    return "";
}

char **getFilesName(char **file, int nbLines, int* NbFiles)
{
    int countFiles = 0;
    char **fileNames = malloc(sizeof(char*) * 20); // MAX 20 FILES. BAD IDEA
    for(int i = 0; i < nbLines - 1; i++)
    {
        if (strstr(file[i], "excludedFiles") != NULL) {
            i++;
            char *p = NULL;
            while(file[i][0] == '-') {
                p = strrchr(file[i], ' ');
                if (p && *(p + 1)) {
                    fileNames[countFiles] = p + 1;
                    countFiles++;
                }
                i++;
            }
            break;
        }
    }
    *NbFiles = countFiles;
    return fileNames;
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
    conf->extends = getExtends(configText, nbLines);
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
    conf->excludedFiles = getFilesName(configText, nbLines, &(conf->nbExcludedFiles));
    conf->recursive = 0;
    return conf;
}