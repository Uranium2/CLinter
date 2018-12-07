//
// Created by theo on 03/12/18.
//

#include <stdlib.h>
#include <stdio.h>
#include "linterMemory.h"

LinterMemory *addElement(char *type, int line, int position, char *filename)
{
    LinterMemory *lm = malloc(sizeof(LinterMemory));
    lm->type = type;
    lm->filename = filename;
    lm->position = position;
    lm->line = line;
    lm->next = NULL;
    return lm;
}
void freeLinterMemory(LinterMemory *lm)
{
    if (lm->next != NULL)
        freeLinterMemory(lm->next);
    free(lm);
}
void printLinterMemory(LinterMemory *lm)
{
    while (lm != NULL)
    {
        printf("%s", lm->type);
        printf("%s", lm->filename);
        printf("%d", lm->position);
        printf("%d", lm->line);
        lm = lm->next;
    }
}