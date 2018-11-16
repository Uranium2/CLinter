#ifndef TOOL
#define TOOL

#include <stdlib.h>
#include <stdio.h>

#include "parser.h"

// Exit the program with a display message
void exit_m(char *message);

// The main printing function to print warning message with filename and position
void print_warning(char *message, int line, int pos, char* fileName);

// Tell if string is a C key word
int isKey(char *str);

// Tell if a string is an Number
int isNum(char *str);

#endif
