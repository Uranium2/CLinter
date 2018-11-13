#include "headers.h"

int main(int argc, char *argv[])
{
	// Load Config file
	Config *conf = loadConfig(getConfigFile(argc, argv));

	char **files = malloc(sizeof(char *) * 255); // 255 files max BAD IDEA
	int pos = 0;
	getFiles(files, &pos, 1, conf->excludedFiles, ".", conf->nbExcludedFiles);
	// Run parsing

	for (int o = 0; o < pos; o++)
	{
		int nbLines = 0;
		char **codeText = getAllLines(files[o], &nbLines);
		for (int i = 0; i < nbLines; i++)
		{
			int nbNodes = 0;
			Token **tokenList = parse(codeText[i], &nbNodes);
			check(tokenList, nbNodes);
			
			for (int j = 0; j < nbNodes; j++)
				printf("%s", tokenList[j]->value);

			if (conf->NoMultiDeclaration)
				multiDeclare(tokenList, nbNodes, nbLines, files[o]);
			if (conf->maxLineNumbers)
				checkmaxLineNumbers(i + 1,
									tokenList[nbNodes - 1]->pos +
										strlen(tokenList[nbNodes - 1]->value),
									conf->maxLineNumbers,
									files[o]);
			if (conf->noTrallingSpaces)
				checkSpace(tokenList, nbNodes, i + 1, files[o]);
			if (conf->arrayBracketEol)
				checkBracket(tokenList, i + 1, files[o]);
			if (conf->operatorsSpacing)
				checkOperator(tokenList, nbNodes, i + 1, files[o]);

			// TokenList
			free_tokenList(tokenList, nbNodes);
		}
		
		if (conf->maxFileLineNumbers)
			checkmaxFileLineNumbers(nbLines, conf->maxFileLineNumbers, files[o]);
		free_text(codeText, nbLines);
	}

	free_conf(conf);
	free_files(files, pos);
	return 0;
}