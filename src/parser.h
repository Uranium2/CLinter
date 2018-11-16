#ifndef PARSER
#define PARSER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "tool.h"
#include "token.h"
#include "checker.h"
#include "changeType.h"

// Color defines
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

// Reads a string and prints each token type
// char* str : input string (code from given file)
// int nbNodes : nbNodes in str
Token **parse(char *str, int* nbNodes);


// Tell if char is an operator
int isOpe(char c);

// Tell if char is a delimiter + operator
int isDelim(char c);

// Tell if char is a delimiter expect space ' '
int isDelimNoSpace(char c);

// Tell if a string has variable format
int isVar(char *str);

// Get subString of str delimited by left and right
char *getSubString(char *str, int left, int right);

#endif
