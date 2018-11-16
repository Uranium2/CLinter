#include "headers.h"

/**
* @file changeType.c
* @brief This c file will contain all the logic to analyze and warn a user of it's bad C type skills.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/


/**
 * @brief The main entrance point of the program containing all the Logic.
 * 
 * @param argc Number of arguments
 * @param argv List of arguments
 * @return int 0 Good else Bad
 */
int main(int argc, char *argv[])
{
	// Load Config file
	Config *conf = loadConfig(getConfigFile(argc, argv));

	char **files = malloc(sizeof(char *) * 255); // 255 files max BAD IDEA
	int pos = 0;
	getFiles(files, &pos, conf->recursive, conf->excludedFiles, ".", conf->nbExcludedFiles);
	// Run parsing

	for (int o = 0; o < pos; o++)
	{
		int nbLines = 0;
		int statusHeader = 0;
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
			if (conf->commentsHeader)
				checkCommentsHeader(tokenList, nbNodes, i + 1, files[o], &statusHeader, nbLines - 1);

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