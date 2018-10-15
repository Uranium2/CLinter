#include "files.h"


int countLinesInFile(FILE* f) {
	int count = 0;
	char* line = NULL;
	size_t len = 0;
	while ((getline(&line, &len, f)) != -1) {
		count++;
	}
	return count;
}


char** getAllLines(char* path, int* nbLines) {
	FILE* f = fopen(path, "r");
	if (f == NULL)
		exit_m("getAllLines: f == NULL");
	char* line = NULL;
	size_t len = 0;
	*nbLines = countLinesInFile(f);
	char** text = malloc(sizeof(char*) * *nbLines);
	int index = 0;
	rewind(f); // reset pointer to start of file
	while ((getline(&line, &len, f)) != -1) {
		printf("READ: %s", line);
		text[index] = line;
		line = NULL;
		index++;
	}

	fclose(f);
	return text;
}
