#ifndef TOOL
#define TOOL

#include <stdlib.h>
#include <stdio.h>

#include "parser.h"

// Exit the program with a display message
void exit_m(char *message);
void print_warning(char *message, int line, int pos, char* fileName);

#endif
