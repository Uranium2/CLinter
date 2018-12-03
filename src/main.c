/**
* @file main.c
* @brief This C file will contain all the logic to analyze and warn a user of his bad C type skills.
* @author Antoine TAVERNIER
* @date 16/11/2018
*/
#include "headers.h"


/**
 * @brief The main entrance point of the program containing all the logic.
 * @param argc Number of arguments
 * @param argv List of arguments
 * @return int 0 Good else Bad
 */
int main(int argc, char *argv[]) {
    // Load Config file
    Config *conf = loadConfig(getConfigFile(argc, argv));
    char **files = malloc(sizeof(char *) * 255); // 255 files max BAD IDEA
    int pos = 0;
    int inComment = 0;
    getFiles(files, &pos, conf->recursive, conf->excludedFiles, ".", conf->nbExcludedFiles);
    // Run parsing
    for (int o = 0; o < pos; o++) { // For each files
        int nbLines = 0;
        int statusHeader = 0;
        Stack *stack = stackInit();
        char **codeText = getAllLines(files[o], &nbLines);
        for (int i = 0; i < nbLines; i++) { // For each lines in File
            int nbNodes = 0;
            Token **tokenList = parse(codeText[i], &nbNodes, &inComment);
            if (nbNodes == 0)
                continue;

            for (int j = 0; j < nbNodes; j++)
                printf("%s", tokenList[j]->value);

            check(tokenList, nbNodes, stack);

            if (conf->NoMultiDeclaration)
                multiDeclare(tokenList, nbNodes, nbLines, files[o], &inComment);
            if (conf->maxLineNumbers)
                checkMaxLineNumbers(i + 1,
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
            if (conf->unusedVariable)
                checkUnusedVariable(tokenList, nbNodes, i + 1, files[o]);

            // TokenList
            //free_tokenList(tokenList, nbNodes);
        }
        if (conf->maxFileLineNumbers)
            checkmaxFileLineNumbers(nbLines, conf->maxFileLineNumbers, files[o]);
        if (conf->unusedVariable)
            checkUnusedVar(stack);
        if (conf->unusedFunction)
            checkUnusedFunc(stack);
        free_text(codeText, nbLines);
    }

    free_conf(conf);
    free_files(files, pos);
    return 0;
}