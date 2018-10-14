#include "headers.h"

int main(int argc, char* argv[]) {
	argc = argc;
	argv = argv;
	parse("int a = 10 + 34;");
	parse("int a=10+34");
	int nbLines = 0;
	char** codeText = getAllLines("README.md", &nbLines);
	for (int i = 0; i < 2; i++)
		printf("%s", codeText[i]);
	return 0;
}
