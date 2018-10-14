#include "parser.h"

// Tell if char is an operator
int isOpe(char c) {
	return (c == '=' || c == '+' ||
			c == '-' || c == '*' ||
			c == '^' || c == '%' || 
			c == '>' || c == '<' ||
			c == '/');
}

// Tell if char is a delimiter + operator
int isDelim(char c) {
	return (c == ' ' || c == ';' ||
			c == '[' || c == ']' ||
			c == '(' || c == ')' ||
			c == '{' || c == '}' ||
			isOpe(c));
}

// Tell if char is a delimiter expect space ' '
int isDelimNoSpace(char c) {
	if (c == ' ')
		return 0;
	return (c == ';' ||
			c == '[' || c == ']' ||
			c == '(' || c == ')' ||
			c == '{' || c == '}' ||
			isOpe(c));
}

// Get subString of str delimited by left and right
char* getSubString(char* str, int left, int right) {
	if (left > right)
		exit_m("getSubString: left > right");
	if (str == NULL)
		exit_m("getSubString: str == NULL");
	char* res = malloc(sizeof(char) * (right - left + 2));
	int i = left;
	for (; i < right + 1; i++) {
		res[i - left] = str[i];
	}
	res[i] = '\0';
	return res;
}



// Reads a string and prints each token type
// char* str : input string (code from given file)
void parse(char* str) {
	printf("%s\n", str);
	int left = 0;
	int right = 0;
	int len = strlen(str);

	while (right <= len - 1 && right >= left) { // stop when reach end of string or left cursor reaches right cursor

		if (!isDelim(str[right])) // extend right until end of "word"
			right++;
		if (isDelim(str[right]) && left == right) {
			printf("%c\n", str[right]);
			right++;
			left = right;
		} else if ((isDelim(str[right]) && left != right) || (right == len && left != right)) {
			char* sub = getSubString(str, left, right);
			int lastPos = strlen(sub) - 1;
			if (isDelimNoSpace(sub[lastPos])) // remove delimiter in subString at last pos
				sub[lastPos] = '\0';
			printf("%s \n", sub);
			left = right;
		}
	}
	if (str[len - 1] == ';')
		printf("END OF LINE\n");
}
