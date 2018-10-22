#ifndef CONFIG
#define CONFIG

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"

typedef struct Config_t
{
    short EFO_Space;
    char **exclusion;
} Config;

// Reads a file and loads the configuration
Config *loadConfig(char *path);

#endif
