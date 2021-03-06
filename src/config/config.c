/**
* @file config.c
* @brief This c file will contain all functions to load a lconf file.
* @author Antoine TAVERNIER
* @date 16/11/2018
*/
#include "config.h"

/**
 * @brief Fill the conf structure with default values.
 * 
 * @param conf A default configuration.
 */
void defaultConf(Config *conf)
{
    conf->extends = NULL;
    conf->arrayBracketEol = 0;
    conf->operatorsSpacing = 0;
    conf->commaSpacing = 0;
    conf->indent = -1;
    conf->commentsHeader = 0;
    conf->maxLineNumbers = SHRT_MAX;
    conf->maxFileLineNumbers = SHRT_MAX;
    conf->noTrallingSpaces = 0;
    conf->NoMultiDeclaration = 0;
    conf->unusedVariable = 0;
    conf->undeclaredVariable = 0;
    conf->noPrototype = 0;
    conf->unusedFunction = 0;
    conf->undeclaredFunction = 0;
    conf->variableAssignmentType = 0;
    conf->functionParametersType = 0;
    conf->excludedFiles = NULL;
    conf->recursive = 0;
}

/**
 * @brief Prints debug file content
 * @param Config struct
 */
void debug_config(Config *r)
{
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
        r->nbExcludedFiles);
}

/**
 * @brief Merge 2 texts content
 * @param txt1 List of strings 1
 * @param nb1  Number of strings in 1, updated with sum of nb1, nb2
 * @param txt2 List of strings 2
 * @param nb2 Number of strings in 2
 * @return char** The total content of both texts
 */
char **mergeText(char **txt1, int *nb1, char **txt2, int *nb2, Collector *c)
{
    int nbTotal = *nb1 + *nb2;
    char **txt3 = malloc_collect(c, sizeof(char *) * nbTotal);
    int j = 0;

    for (int i = 0; i < *nb1; i++)
        txt3[i] = txt1[i];

    for (int i = *nb1; i < nbTotal; i++)
    {
        txt3[i] = txt2[j];
        j++;
    }
    *nb1 = nbTotal;
    return txt3;
}

/**
 * @brief Get the Config File
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
 * @param file List of Strings represented by a file
 * @param nbLines Number of lines in the file
 * @return char* A file name
 */
char *getExtends(char **file, int nbLines, Collector *c)
{

    for (int i = 0; i < nbLines - 1; i++)
    {
        if (strstr(file[i], "extends") != NULL)
        {
            char *res = malloc_collect(c, sizeof(char) * strlen(file[i + 1]));
            res = file[i + 1];
            return res;
        }
    }
    return "";
}

/**
 * @brief Get list of excluded files in lconf
 * @param file List of Strings represented by a file 
 * @param nbLines Number of lines in the file
 * @param NbFiles Number of excluded files updated
 * @return char** List of files name
 */
char **getFilesName(char **file, int nbLines, int *NbFiles, Collector *c)
{
    int countFiles = 0;
    char **fileNames = malloc_collect(c, sizeof(char *) * 20); // MAX 20 FILES. BAD IDEA
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
                if (strstr(file[i], "on\n") != NULL)
                    return 1;
                if (strstr(file[i], "off\n") != NULL)
                    return 0;
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
 * @brief Check if a given file has already been loaded.
 * 
 * @param conf Original configuration structure
 * @param path The path to the new configuration to merge with the original structure
 * @return 0 false else true
 */
int containsConfigFile(Config *conf, char *path)
{
    int index = 0;
    while (path[index] != '\0')
        index++;
    path[index - 1] = '\0'; // remove \n and the end of path

    for (int i = 0; i < conf->nbconfigFileName; i++)
        if (strcmp(conf->configFileName[i], path) == 0)
            return 1;
    return 0;
}

/**
 * @brief Merge 2 configurations
 * 
 * @param conf Original configuration structure
 * @param path The path to the new configuration to merge with the original structure
 */
void mergeConf(Config *conf, char *path, Collector *c)
{
    // check if conf is already loaded
    if (containsConfigFile(conf, path))
        return;

    char **configText;
    int nbLines = 0;
    if (!isValidConfFile(path))
        return;
    else
        configText = getAllLines(path, &nbLines, c);
    if (configText == NULL)
        return;

    Config *conf2 = malloc_collect(c, sizeof(Config));
    conf2->extends = getExtends(configText, nbLines, c);
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
    conf2->excludedFiles = getFilesName(configText, nbLines, &(conf2->nbExcludedFiles), c);
    conf2->recursive = getRecursive(configText, nbLines);

    conf->extends = conf2->extends;
    conf->arrayBracketEol += conf2->arrayBracketEol;
    conf->operatorsSpacing += conf2->operatorsSpacing;
    conf->commaSpacing += conf2->commaSpacing;
    conf->indent += conf2->indent;
    conf->commentsHeader += conf2->commentsHeader;
    conf->maxLineNumbers = MIN(conf->maxLineNumbers, conf2->maxLineNumbers);
    conf->maxFileLineNumbers = MIN(conf->maxFileLineNumbers, conf2->maxFileLineNumbers);
    conf->noTrallingSpaces += conf2->noTrallingSpaces;
    conf->NoMultiDeclaration += conf->NoMultiDeclaration;
    conf->unusedVariable += conf->unusedVariable;
    conf->undeclaredVariable += conf->undeclaredVariable;
    conf->noPrototype += conf->noPrototype;
    conf->unusedFunction += conf->unusedFunction;
    conf->undeclaredFunction += conf->undeclaredFunction;
    conf->variableAssignmentType += conf->variableAssignmentType;
    conf->functionParametersType += conf->functionParametersType;
    conf->excludedFiles = mergeText(conf->excludedFiles, &conf->nbExcludedFiles, conf2->excludedFiles,
                                    &conf2->nbExcludedFiles, c);
    conf->recursive += conf->recursive;
    mergeConf(conf, conf->extends, c);
    free_text(configText, nbLines);
}

/**
 * @brief Load the configuration from a file
 * 
 * @param path Configuration file
 * @return Config* Configuration structure from given file
 */
Config *loadConfig(char *path, Collector *c)
{
    char **configText;
    int nbLines = 0;
    Config *conf = malloc_collect(c, sizeof(Config));
    conf->nbconfigFileName = 0;
    conf->configFileName = malloc_collect(c, sizeof(char *) * 100); // "only 100 files"

    if (!isValidConfFile(path))
    {
        configText = getAllLines("default.lconf", &nbLines, c);
        if (configText == NULL)
        {
            defaultConf(conf);
            return conf;
        }
        conf->configFileName[conf->nbconfigFileName] = "default.lconf";
        conf->nbconfigFileName++;
    }
    else
    {
        configText = getAllLines(path, &nbLines, c);
        if (configText == NULL)
        {
            defaultConf(conf);
            return conf;
        }
        conf->configFileName[conf->nbconfigFileName] = path;
        conf->nbconfigFileName++;
    }

    conf->extends = getExtends(configText, nbLines, c);
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
    conf->excludedFiles = getFilesName(configText, nbLines, &(conf->nbExcludedFiles), c);
    conf->recursive = getRecursive(configText, nbLines);

    if (conf->extends != NULL || conf->extends[0] != '\0')
        mergeConf(conf, conf->extends, c);
    free_text(configText, nbLines);
    return conf;
}