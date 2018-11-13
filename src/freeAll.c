#include "freeAll.h"

void clean_text(char **codeText, int nbLines)
{
    if (nbLines < 1)
        return;

    for(int i = 0; i < nbLines; i++)
    {
        
        for(int j = 0; j < 255; j++)
        {
            codeText[i][j] = '\0';
        }
        
    }
    
}

void free_files(char** files, int nbFiles)
{
    if (nbFiles < 1)
        return;

    for(int i = 0; i < nbFiles; i++)
        free(files[i]);

    free(files);
}

void free_tokenList(Token **tokenList, int nbNodes)
{
    if (nbNodes < 1)
        return;

    for (int j = 0; j < nbNodes; j++)
    {
        free(tokenList[j]->value);
        free(tokenList[j]);
    }
    free(tokenList);
}

void free_text(char **codeText, int nbLines)
{
    if (nbLines < 1)
        return;

    for (int i = 0; i < nbLines; i++)
        free(codeText[i]);
}

void free_conf(Config *conf)
{
    if (conf == NULL)
        return;
    //Free ExcludedFiles[i]?

    free(conf->excludedFiles);
    if (conf->extends == NULL)
        free(conf->extends);
    free(conf);
}