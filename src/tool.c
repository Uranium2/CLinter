#include "tool.h"

void exit_m(char *message)
{
	printf("FORCE EXIT BECAUSE \"%s\" FAILED\n", message);
	exit(1);
}

void print_warning(char *message, int line, int pos, char *fileName)
{
	//if (fileName == NULL)
	//	printf("FileName is NULL %s", fileName);
	printf(YEL "%s at line " RED "%d" YEL " character for " RED "%d " YEL "for file " RED "%s\n" RESET, message, line, pos, fileName);
}

// Tell if string is a C key word
int isKey(char *str)
{
	return (!strcmp(str, "int") || !strcmp(str, "float") ||
			!strcmp(str, "double") || !strcmp(str, "char") ||
			!strcmp(str, "if") || !strcmp(str, "else") ||
			!strcmp(str, "while") || !strcmp(str, "do") ||
			!strcmp(str, "for") || !strcmp(str, "unsigned") ||
			!strcmp(str, "break") || !strcmp(str, "continue") ||
			!strcmp(str, "switch") || !strcmp(str, "return") ||
			!strcmp(str, "case") || !strcmp(str, "short") ||
			!strcmp(str, "static") || !strcmp(str, "void") ||
			!strcmp(str, "struct"));
}

// Tell if a string is an Number
int isNum(char *str)
{
    if (str == NULL)
        exit_m("isNum: str == NULL");
    int len = strlen(str);
    if (len <= 0)
        return 0;
    char *end;
    strtod(str, &end);
    if (end == str)
        return 0;
    if (strlen(end) > 0)
        return 0;
    return 1;
}