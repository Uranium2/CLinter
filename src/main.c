#include "headers.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
		exit_m("main.c: ARGUMENTS COUNT");

	// Load Config file
	Config *conf = loadConfig(argv[2]);

	// Run parsing
	int nbLines = 0;
	char **codeText = getAllLines(argv[1], &nbLines);
	for (int i = 0; i < nbLines; i++)
	{
		int nbNodes = 0;
		Token **tokenList = parse(codeText[i], &nbNodes);
		check(tokenList, nbNodes);
	}
	return 0;
}
