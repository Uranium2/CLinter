#include "headers.h"

int main(int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
		exit_m("main.c: ARGUMENTS COUNT");

	// Load Config file
	char *path = "";
	if ( argc == 3)
		path = argv[2];
	Config *conf = loadConfig(path);

	// Run parsing
	int nbLines = 0;
	char **codeText = getAllLines(argv[1], &nbLines);
	for (int i = 0; i < nbLines; i++)
	{
		int nbNodes = 0;
		Token **tokenList = parse(codeText[i], &nbNodes);
		//check(tokenList, nbNodes);
		
		for(int j = 0; j < nbNodes; j++)
			printf("%s", tokenList[j]->value);
		
		
		if (conf->noTrallingSpaces)
			checkSpaceEOL(tokenList, nbNodes, i + 1);
		if (conf->arrayBracketEol)
			checkBracketEOL(tokenList, i + 1);
		if (conf->operatorsSpacing)
			checkOperatorEOL(tokenList,nbNodes, i + 1);
	}
	if (conf->maxFileLineNumbers)
		checkmaxFileLineNumbers(nbLines, conf->maxFileLineNumbers);
	return 0;
}