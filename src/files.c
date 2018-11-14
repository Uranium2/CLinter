#include "files.h"

int countLinesInFile(FILE *f)
{
	int count = 0;
	char *line = NULL;
	size_t len = 0;
	while ((getline(&line, &len, f)) != -1)
	{
		count++;
	}
	free(line);
	return count;
}

char **getAllLines(char *path, int *nbLines)
{
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
	while ((getline(&line, &len, f)) != -1)
	{
		text[index] = line;
		line = NULL;
		index++;
	}
	free(line);
	fclose(f);
	return text;
}
