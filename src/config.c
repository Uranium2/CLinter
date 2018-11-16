#include "config.h"
/**
* @file config.c
* @brief This c file will contain all functions to load a lconf file.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/

/**
 * @brief Merge 2 texts content
 * 
 * @param txt1 List of strings 1
 * @param nb1  Number of strings in 1, updated with sum of nb1, nb2
 * @param txt2 List of strings 2
 * @param nb2 Number of strings in 2
 * @return char** The total content of both texts
 */
char **mergeText(char** txt1, int *nb1, char** txt2, int *nb2)
{
    int nbTotal = *nb1 + *nb2;
    char **txt3 = malloc(sizeof(char*) * nbTotal);
    int j = 0;
    
    for(int i = 0; i < *nb1; i++)
        txt3[i] = txt1[i];
    
    for(int i = *nb1 ; i < nbTotal; i++)
    {
        txt3[i] = txt2[j];
        j++;
    }
    *nb1 = nbTotal;
    return txt3;
}

/**
 * @brief Get the Config File
 * 
 * @param argc Number of argument of main
 * @param argv List of argument of main
 * @return char* Name of config file
 */
char *getConfigFile(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        if (strstr(argv[i], ".lconf") != NULL)
            return argv[i];
    return "default.lconf";
}

/**
 * @brief Check if a given file has good name format
 * 
 * @param filename A file path
 * @return int false (0) if not contains .lconf else true (1)
 */
int isValidConfFile(char *filename)
{
    char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return 0;

    if (strcmp(dot, "lconf"))
        return 1;
    return 0;
}

/**
 * @brief Get the Recursive option value
 * 
 * @param file List of Strings represented by a file
 * @param nbLines Number of lines in the file
 * @return short 0 false else true
 */
short getRecursive(char **file, int nbLines)
{

    for (int i = 0; i < nbLines - 1; i++)
    {
        if (strstr(file[i], "=recursive") != NULL)
        {
            if (strstr(file[i + 1], "true") != NULL)
                return 1;
        }
    }
    return 0;
}

/**
 * @brief Get the Extends file name
 * 
 * @param file List of Strings represented by a file
 * @param nbLines Number of lines in the file
 * @return char* A file name
 */
char *getExtends(char **file, int nbLines)
{

    for (int i = 0; i < nbLines - 1; i++)
    {
        if (strstr(file[i], "extends") != NULL)
        {
            char *res = malloc(sizeof(char) * strlen(file[i + 1]));
            res = file[i + 1];
            return res;
        }
    }
    return "";
}

/**
 * @brief Get list of excluded files in lconf
 * 
 * @param file List of Strings represented by a file 
 * @param nbLines Number of lines in the file
 * @param NbFiles Number of excluded files updated
 * @return char** List of files name
 */
char **getFilesName(char **file, int nbLines, int *NbFiles)
{
    int countFiles = 0;
    char **fileNames = malloc(sizeof(char *) * 20); // MAX 20 FILES. BAD IDEA
    for (int i = 0; i < nbLines - 1; i++)
    {
        if (strstr(file[i], "excludedFiles") != NULL)
        {
            i++;
            char *p = NULL;
            while (file[i][0] == '-')
            {
                p = strrchr(file[i], ' ');
                if (p && *(p + 1))
                {
                    fileNames[countFiles] = p + 1;
                    countFiles++;
                }
                i++;
            }
            break;
        }
    }
    *NbFiles = countFiles;

    for (int i = 0; i < countFiles; i++)
        for (unsigned j = 0; j < strlen(fileNames[i]); j++)
            if (fileNames[i][j] == '\n')
                fileNames[i][j] = '\0';

    return fileNames;
}

/**
 * @brief Get the value of a field in a config
 * 
 * @param file List of Strings represented by a file
 * @param rule String representation of a rule in the lconf file
 * @param nbLines Number of lines in the lconf file
 * @return int 0 false else true
 */
int getVal(char **file, char *rule, int nbLines)
{

    for (int i = 0; i < nbLines; i++)
    {

        if (strstr(file[i], rule) != NULL)
        {
            char *p = strrchr(file[i], ' ');
            if (p && *(p + 1))
            {
                if (strstr(file[i], "on") != NULL)
                    return 1;
                if (strstr(file[i], "off") != NULL)
                    return 0;
                return atoi(p + 1);
            }
        }
    }
    return 0;
}

/**
 * @brief Merge 2 configurations
 * 
 * @param conf Original configuration structure
 * @param path The path to the new configuration to merge with the original structure
 */
void mergeConf(Config *conf, char *path)
{
    char **configText;
    int nbLines = 0;
    configText = getAllLines(path, &nbLines);

    Config *conf2 = malloc(sizeof(Config));
    conf2->extends = getExtends(configText, nbLines);
    conf2->arrayBracketEol = getVal(configText, "array-bracket-eol", nbLines);
    conf2->operatorsSpacing = getVal(configText, "operators-spacing", nbLines);
    conf2->commaSpacing = getVal(configText, "comma-spacing", nbLines);
    conf2->indent = getVal(configText, "indent", nbLines); // nb space of indend
    conf2->commentsHeader = getVal(configText, "comments-header", nbLines);
    conf2->maxLineNumbers = getVal(configText, "max-line-numbers", nbLines);          // nb Max char per line
    conf2->maxFileLineNumbers = getVal(configText, "max-file-line-numbers", nbLines); // nb Max line per file
    conf2->noTrallingSpaces = getVal(configText, "no-trailing-spaces", nbLines);
    conf2->NoMultiDeclaration = getVal(configText, "no-multi-declaration", nbLines);
    conf2->unusedVariable = getVal(configText, "unused-variable", nbLines);
    conf2->undeclaredVariable = getVal(configText, "undeclared-variable", nbLines);
    conf2->noPrototype = getVal(configText, "no-prototype", nbLines);
    conf2->unusedFunction = getVal(configText, "unused-function", nbLines);
    conf2->undeclaredFunction = getVal(configText, "undeclared-function", nbLines);
    conf2->variableAssignmentType = getVal(configText, "variable-assignment-type", nbLines);
    conf2->functionParametersType = getVal(configText, "function-parameters-type", nbLines);
    conf2->excludedFiles = getFilesName(configText, nbLines, &(conf2->nbExcludedFiles));
    conf2->recursive = getRecursive(configText, nbLines);

    conf->arrayBracketEol += conf2->arrayBracketEol;
    conf->operatorsSpacing += conf2->operatorsSpacing;
    conf->commaSpacing += conf2->commaSpacing;
    conf->indent += conf2->indent;
    conf->commentsHeader += conf2->commentsHeader;
    conf->maxLineNumbers = MAX(conf->maxLineNumbers, conf2->maxLineNumbers);
    conf->maxFileLineNumbers = MAX(conf->maxFileLineNumbers, conf2->maxFileLineNumbers);
    conf->noTrallingSpaces += conf2->noTrallingSpaces;
    conf->NoMultiDeclaration += conf->NoMultiDeclaration;
    conf->unusedVariable += conf->unusedVariable;
    conf->undeclaredVariable += conf->undeclaredVariable;
    conf->noPrototype += conf->noPrototype;
    conf->unusedFunction += conf->unusedFunction;
    conf->undeclaredFunction += conf->undeclaredFunction;
    conf->variableAssignmentType += conf->variableAssignmentType;
    conf->functionParametersType += conf->functionParametersType;
    conf->excludedFiles = mergeText(conf->excludedFiles, &conf->nbExcludedFiles, conf2->excludedFiles, &conf2->nbExcludedFiles);
    conf->recursive += conf->recursive;
}

/**
 * @brief Load the configuration from a file
 * 
 * @param path Configuration file
 * @return Config* Configuration structure from given file
 */
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
    conf->maxLineNumbers = getVal(configText, "max-line-numbers", nbLines);          // nb Max char per line
    conf->maxFileLineNumbers = getVal(configText, "max-file-line-numbers", nbLines); // nb Max line per file
    conf->noTrallingSpaces = getVal(configText, "no-trailing-spaces", nbLines);
    conf->NoMultiDeclaration = getVal(configText, "no-multi-declaration", nbLines);
    conf->unusedVariable = getVal(configText, "unused-variable", nbLines);
    conf->undeclaredVariable = getVal(configText, "undeclared-variable", nbLines);
    conf->noPrototype = getVal(configText, "no-prototype", nbLines);
    conf->unusedFunction = getVal(configText, "unused-function", nbLines);
    conf->undeclaredFunction = getVal(configText, "undeclared-function", nbLines);
    conf->variableAssignmentType = getVal(configText, "variable-assignment-type", nbLines);
    conf->functionParametersType = getVal(configText, "function-parameters-type", nbLines);
    conf->excludedFiles = getFilesName(configText, nbLines, &(conf->nbExcludedFiles));
    conf->recursive = getRecursive(configText, nbLines);

    if (conf->extends != NULL || conf->extends[0] != '\0')
        mergeConf(conf, conf->extends);
    return conf;
}