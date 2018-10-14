#include "headers.h"

int main(int argc, char* argv[]) {
	argc = argc;
	argv = argv;
	parse("int a = 10 + 34;");
	parse("int a=10+34");
	return 0;
}
