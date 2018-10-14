#include "parser.h"

int isDelim(char c) {
	return (c == ' ');
}



// Reads a string and prints each token type
// char* str : input string (code from given file)
void parse(char* str) {
	int left = 0;
	int right = 0;
	int len = strlen(str);

	while (right <= len && right >= left) { // stop when reach end of string or left cursor reaches right cursor
		printf("%c\n", str[right]);

		if (!isDelim(str[right])) // extend right until end of "word"
			right++;
		if (isDelim(str[right]) && left == right) {
			right++;
			left = right;
		} else if ((isDelim(str[right]) && left != right) || (right == len && left != right)) {
				printf("left = %d right = %i\n", left, right);
				left = right;
		}
	}
}
