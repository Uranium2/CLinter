/**
* @file parser.h
* @brief This header file will contain all required
* definitions and basic utilities functions to transform text into Tokens.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#ifndef PARSER
#define PARSER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "../tools/tool.h"
#include "../parse/token.h"
#include "changeType.h"
#include "../tools/collector.h"


Token **parse(char *str, int *nbNodes, int *inComment, Collector *c);

int isOpe(char c);

int isDelim(char c);

int isDelimNoSpace(char c);

char *getSubString(char *str, int left, int right, Collector *c);

#endif
