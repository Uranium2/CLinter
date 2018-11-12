#include "freeAll.h"

void free_files(char** files, int nbFiles)
{
    
    for(int i = 0; i < nbFiles; i++)
        free(files[i]);

    free(files);
}

void free_tokenList(Token **tokenList, int nbNodes)
{
    for (int j = 0; j < nbNodes; j++)
        free(tokenList[j]->value);
    free(tokenList);
}

void free_text(char **codeText, int nbLines)
{
    for (int i = 0; i < nbLines; i++)
        free(codeText[i]);
}

void free_conf(Config *conf)
{
    //Free ExcludedFiles[i]?

    free(conf->excludedFiles);
    free(conf->extends);
    free(conf);
}