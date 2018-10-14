#include "headers.h"

int main(int argc, char* argv[]) {
	argc = argc;
	argv = argv;
	parse("int a = 10 + 34;");
	parse("int a=10+34");
	char** codeText = getAllLines("README.md");
	for (int i = 0; i < 2; i++)
		printf("%s", codeText[i]);
	return 0;
}
