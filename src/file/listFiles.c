/**
* @file listFiles.c
* @brief This c file will contain all functions to list files we want to work on.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#include "listFiles.h"

/**
 * @brief Check if a given file is not in the list of excluded files from config
 * 
 * @param excludedFiles List of excluded files
 * @param file The given file to check
 * @param length Number of exlucded files in the list
 * @return int 0 false else true
 */
int isNotExcluded(char **excludedFiles, char *file, int length) {

    if (excludedFiles == NULL)
        return 1;
    for (int i = 0; i < length; i++)
        if (strcmp(excludedFiles[i], file) == 0)
            return 0;
    return 1;
}

/**
 * @brief Get the Files from list a path
 * 
 * @param files A list of File names
 * @param pos Position in the list of File names
 * @param isRecursive 0 false else true
 * @param excludedFiles List of excluded files
 * @param path Path of the file
 * @param length Number of excluded files
 */
void getFiles(char **files, int *pos, short isRecursive, char **excludedFiles,
              char *path, int length) {
    char newPath[100];
    struct dirent *dp;
    DIR *dir = opendir(path);
    if (!dir)
        exit(2);
    while ((dp = readdir(dir)) != NULL) {
        if (!(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)) {
            if (strstr(dp->d_name, ".c") != NULL && isNotExcluded(excludedFiles, dp->d_name, length) &&
                dp->d_name[strlen(dp->d_name) - 1] == 'c') {
                char *str = malloc(sizeof(char) * 255); // length max file name 255
                strcpy(str, path);
                strcat(str, "/");
                strcat(str, dp->d_name);
                files[*pos] = str;
                *pos = *pos + 1;
            } else {
                // check config for recursive
                if (isRecursive) {
                    if (dp->d_type == DT_DIR) {
                        strcpy(newPath, path);
                        strcat(newPath, "/");
                        strcat(newPath, dp->d_name);
                        getFiles(files, pos, isRecursive, excludedFiles, newPath, length);
                    }
                }
            }
        }
    }
    closedir(dir);
}
