#include "headers.h"

int main(int argc, char *argv[])
{
	// Load Config file
	char *path = "";
	if (argc == 3)
		path = argv[2];
	Config *conf = loadConfig(path);
	char **files = malloc(sizeof(char*) * 255); // 255 files max BAD IDEA
	int pos = 0;
	getFiles(files, &pos, 1, conf->excludedFiles, ".", conf->nbExcludedFiles);
	// Run parsing
	int nbLines = 0;
	char **codeText = getAllLines(argv[1], &nbLines);
	for (int i = 0; i < nbLines; i++)
	{
		int nbNodes = 0;
		Token **tokenList = parse(codeText[i], &nbNodes);
		check(tokenList, nbNodes);

		for (int j = 0; j < nbNodes; j++)
			printf("%s %s ", tokenList[j]->value, getEnumName(tokenList[j]->type));

		if (conf->NoMultiDeclaration)
			multiDeclare(tokenList, nbNodes, nbLines);
		if (conf->maxLineNumbers)
			checkmaxLineNumbers(i + 1,
								tokenList[nbNodes - 1]->pos +
									strlen(tokenList[nbNodes - 1]->value),
								conf->maxLineNumbers);
		if (conf->noTrallingSpaces)
			checkSpace(tokenList, nbNodes, i + 1);
		if (conf->arrayBracketEol)
			checkBracket(tokenList, i + 1);
		if (conf->operatorsSpacing)
			checkOperator(tokenList, nbNodes, i + 1);

		// TokenList	
		free_tokenList(tokenList, nbNodes);
	}
	if (conf->maxFileLineNumbers)
		checkmaxFileLineNumbers(nbLines, conf->maxFileLineNumbers);

	free_files(files, 255);
	free_text(codeText, nbLines);
	free_conf(conf);
	return 0;
}