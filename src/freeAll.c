/**
* @file freeAll.c
* @brief This c file will contain all functions to free all structures and pointers.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#include "freeAll.h"

/**
 * @brief Replace all characters by '\0' in codeText to wipe all Data.
 * 
 * @param codeText A list of string
 * @param nbLines Number of strings in the list
 */
void clean_text(char **codeText, int nbLines) {
    if (nbLines < 1) {
        return;
    }

    for (int i = 0; i < nbLines; i++) {

        for (int j = 0; j < 255; j++) {
            codeText[i][j] = '\0';
        }

    }

}

/**
 * @brief Free list of files (string). Similar has free_text
 * 
 * @param files List of files
 * @param nbFiles Number of files in the list
 */
void free_files(char **files, int nbFiles) {
    if (nbFiles < 1) {
        return;
    }

    for (int i = 0; i < nbFiles; i++)
        free(files[i]);

    free(files);
}

/**
 * @brief Free content of a list of Tokens
 * 
 * @param tokenList List of Tokens to free
 * @param nbNodes Numbers of Tokens in the list
 */
void free_tokenList(Token **tokenList, int nbNodes) {
    if (nbNodes < 1) {
        return;
    }

    for (int j = 0; j < nbNodes; j++) {
        free(tokenList[j]->value);
        free(tokenList[j]);
    }
    free(tokenList);
}

/**
 * @brief Free code Text
 * 
 * @param codeText A list of string
 * @param nbLines Number of strings in the list
 */
void free_text(char **codeText, int nbLines) {
    if (nbLines < 1) {
        return;
    }

    for (int i = 0; i < nbLines; i++)
        free(codeText[i]);
}

/**
 * @brief Free the configuration structure
 * 
 * @param conf Config structure
 */
void free_conf(Config *conf) {
    if (conf == NULL){
        return;
    }
    //Free ExcludedFiles[i]?

    free(conf->excludedFiles);
    if (conf->extends == NULL) {
        free(conf->extends);
    }
    free(conf);
}