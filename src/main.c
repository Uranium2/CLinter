/**
* @file main.c
* @brief This C file will contain all the logic to analyze and warn a user of his bad C type skills.
* @author Antoine TAVERNIER
* @date 16/11/2018
*/
#include "headers.h"
#include "tools/linterMemory.h"

/**
 * @brief The main entrance point of the program containing all the logic.
 * @param argc Number of arguments
 * @param argv List of arguments
 * @return int 0 Good else Bad
 */
int main(int argc, char *argv[]) {

    // Load Config file
    Config *conf = loadConfig(getConfigFile(argc, argv));
    char **files = malloc(sizeof(char *) * 255);

    //Counters
    int pos = 0;
    int inComment = 0;
    // TODO : Add LinterMemory for unusedvariable etc..
    LinterMemory *lm = addElement("",0,0,NULL);


    getFiles(files, &pos, conf->recursive, conf->excludedFiles, ".", conf->nbExcludedFiles);

    // Run parsing for each files
    for (int o = 0; o < pos; o++) {

        int nbLines = 0;
        int statusHeader = 0;
        Stack *stack = stackInit();
        char **codeText = getAllLines(files[o], &nbLines);

        // Travels each lines in file
        for (int i = 0; i < nbLines; i++) {

            int nbNodes = 0;
            Token **tokenList = parse(codeText[i], &nbNodes, &inComment);

            if (nbNodes == 0) {
                continue;
            }
            for (int j = 0; j < nbNodes; j++) {
                printf("%s", tokenList[j]->value);
            }
            check(tokenList, nbNodes, stack);
            if (conf->NoMultiDeclaration) {
                multiDeclare(tokenList, nbNodes, nbLines, files[o], &inComment);
            }
            if (conf->maxLineNumbers) {
                checkMaxLineNumbers(i + 1, tokenList[nbNodes - 1]->pos + strlen(tokenList[nbNodes - 1]->value),
                                    conf->maxLineNumbers, files[o]);
            }
            if (conf->noTrallingSpaces) {
                checkSpace(tokenList, nbNodes, i + 1, files[o]);
            }
            if (conf->arrayBracketEol) {
                checkBracket(tokenList, i + 1, files[o]);
            }
            if (conf->operatorsSpacing) {
                checkOperator(tokenList, nbNodes, i + 1, files[o]);
            }
            if (conf->commentsHeader) {
                checkCommentsHeader(tokenList, nbNodes, i + 1, files[o], &statusHeader, nbLines - 1);
            }
            if (conf->unusedVariable) {
                checkUnusedVariable(tokenList, nbNodes, i + 1, files[o], &inComment, lm);
            }
            if (conf->unusedFunction) {
                checkUnusedFunction(tokenList, nbNodes, i + 1, files[o], &inComment, lm);
            }
        }
        //stackPrint(stack);
        if (conf->maxFileLineNumbers) {
            checkmaxFileLineNumbers(nbLines, conf->maxFileLineNumbers, files[o]);
        }
        if (conf->unusedVariable) {
            checkUnusedVar(stack, files[o]);
        }
        if (conf->unusedFunction) {
            checkUnusedFunc(stack, files[o]);
        if(conf->undeclaredVariable)
            checkUndeclaredVar(stack, files[0]);
        if(conf->undeclaredFunction)
            checkUndeclaredFunc(stack, files[0]);
        stackPrint(stack);
        free_text(codeText, nbLines);
    }
    freeLinterMemory(lm);
    free_conf(conf);
    free_files(files, pos);

    return 0;
}