#include "listFiles.h"

int isNotExcluded(char ** excludedFiles, char* file, int length)
{
    if (excludedFiles == NULL)
        return 1;
    for (int i = 0; i < length; i++)
    {
        if (strstr(excludedFiles[i], file) == NULL)
            return 1;
    }
    return 0;
}

void getFiles(short isRecursive, char **excludedFiles, char *path, int length)
{
    char newPath[100];
    struct dirent *dp;
    DIR *dir = opendir(path);
    if (!dir)
        exit(2);
    while ((dp = readdir(dir)) != NULL)
    {
        if (!(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) &&
        isNotExcluded(excludedFiles, dp->d_name, length))
        {
            if (strstr(dp->d_name, ".c") != NULL)
                printf("%s/%s\n", path, dp->d_name);
            else
            {
                if (dp->d_type == DT_DIR)
                {
                    strcpy(newPath, path);
                    strcat(newPath, "/");
                    strcat(newPath, dp->d_name);
                    getFiles(isRecursive, excludedFiles, newPath, length);
                }
            }
        }
    }
}