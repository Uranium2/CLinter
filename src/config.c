#include "config.h"

Config *loadConfig(char *path)
{
    int nbLines = 0;
    char **configText = getAllLines(path, &nbLines);
    Config *test;
    return test;
}