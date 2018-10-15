#ifndef PARSER
#define PARSER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <regex.h>

#include "tool.h"

// Reads a string and prints each token type
// char* str : input string (code from given file)
void parse(char* str);

// Tell if a string is an Integer
int isInt(char* str);

#endif
