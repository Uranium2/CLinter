#include "config.h"

int is_valid_conf_file(char *filename)
{
    char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return 0;

    if (strcmp(dot, "lconf"))
        return 1;
    return 0;
}

Config *loadConfig(char *path)
{
    int nbLines = 0;
    char **configText = getAllLines(path, &nbLines);
    Config *conf = malloc(sizeof(Config));
    conf->EFO_Space = 1;
    return conf;
}