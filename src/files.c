/**
* @file files.c
* @brief This c file will contain all functions to load a file in a char**.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#include "files.h"


/**
 * @brief Get the number of lines in a file
 * 
 * @param f Given FILE
 * @return int Number of line in FILE f
 */
int countLinesInFile(FILE *f) {
    int count = 0;
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, f)) != -1) {
        count++;
    }
    free(line);
    return count;
}

/**
 * @brief Get the All Lines in a file
 * 
 * @param path Path of file
 * @param nbLines Number of lines updated in the file
 * @return char** A list of string containing the text of file
 */
char **getAllLines(char *path, int *nbLines) {
    if (path[strlen(path) - 1] == '\n')
        path[strlen(path) - 1] = '\0';
    FILE *f = fopen(path, "r");
    if (f == NULL)
        exit_m("getAllLines: f == NULL");
    char *line = NULL;
    size_t len = 0;
    *nbLines = countLinesInFile(f);
    char **text = malloc(sizeof(char *) * *nbLines);
    int index = 0;
    rewind(f); // reset pointer to start of file
    while ((getline(&line, &len, f)) != -1) {
        text[index] = line;
        line = NULL;
        index++;
    }
    free(line);
    fclose(f);
    return text;
}
