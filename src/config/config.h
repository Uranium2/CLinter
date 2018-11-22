/**
* @file config.h
* @brief This header file will contain all required
* definitions and basic utilities functions to read and load a configuration file.
* @author Antoine TAVERNIER
* @date 16/11/2018
*/
#ifndef CONFIG
#define CONFIG

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../file/files.h"
/**
 * @brief Macro to return MAX between integers
 */
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

/**
 * @brief Structure to store all configurations elements
 */
typedef struct Config_t {
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

char **mergeText(char **txt1, int *nb1, char **txt2, int *nb2);

char *getConfigFile(int argc, char **argv);

int isValidConfFile(char *filename);

short getRecursive(char **file, int nbLines);

char *getExtends(char **file, int nbLines);

char **getFilesName(char **file, int nbLines, int *NbFiles);

int getVal(char **file, char *rule, int nbLines);

Config *loadConfig(char *path);

char *getConfigFile(int argc, char **argv);

#endif
