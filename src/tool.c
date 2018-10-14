#include "tool.h"

void exit_m(char* message) {
	printf("FORCE EXIT BECAUSE \"%s\" FAILED\n", message);
	exit(1);
}
