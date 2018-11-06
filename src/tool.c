#include "tool.h"

void exit_m(char *message)
{
	printf("FORCE EXIT BECAUSE \"%s\" FAILED\n", message);
	exit(1);
}

void print_warning(char *message, int line, int pos)
{
    printf(YEL "%s at line " RED "%d" YEL " character " RED "%d \n" RESET,message, line, pos);
}