#include "headers.h"

int main(int argc, char* argv[]) {
	argc = argc;
	argv = argv;
	int nbLines = 0;
	char** codeText = getAllLines("sample.c", &nbLines);
	for (int i = 0; i < nbLines; i++) {
		parse(codeText[i], i + 1);
	}
	return 0;
}
