#ifndef FREEALL
#define FREEALL

#include <stdlib.h>
#include <stdio.h>

#include "config.h"

void free_conf(Config* conf);
void free_text(char** codeText, int nbLines);
void free_tokenList(Token **tokenList, int nbNodes);
void free_files(char** files, int nbFiles);
#endif
