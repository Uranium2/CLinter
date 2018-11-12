#include "listFiles.h"

int isNotExcluded(char **excludedFiles, char *file, int length)
{

    if (excludedFiles == NULL)
        return 1;
    for (int i = 0; i < length; i++)
        if (strcmp(excludedFiles[i], file) == 0)
            return 0;
    return 1;
}

void getFiles(char **files, int *pos, short isRecursive, char **excludedFiles, char *path, int length)
{
    char newPath[100];
    struct dirent *dp;
    DIR *dir = opendir(path);
    if (!dir)
        exit(2);
    while ((dp = readdir(dir)) != NULL)
    {
        if (!(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0))
        {
            if (strstr(dp->d_name, ".c") != NULL && isNotExcluded(excludedFiles, dp->d_name, length))
            {
                char *str = malloc(sizeof(char) * 255); // length max file name 255
                strcpy(str, path);
                strcat(str, "/");
                strcat(str, dp->d_name);
                printf("%s pos: %d\n", str, *pos);
                files[*pos] = str;
                *pos = *pos + 1;
            }
            else
            {
                if (dp->d_type == DT_DIR)
                {
                    strcpy(newPath, path);
                    strcat(newPath, "/");
                    strcat(newPath, dp->d_name);
                    getFiles(files, pos, isRecursive, excludedFiles, newPath, length);
                }
            }
        }
    }
    closedir(dir);
}