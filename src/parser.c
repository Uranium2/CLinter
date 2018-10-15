#include "parser.h"

// Tell if a string is an Integer
int isInt(char* str) {
	if (str == NULL)
		exit_m("isInt: str == NULL");
	int len = strlen(str);
	if (len <= 0)
		return 0;
	for (int i = 0; i < (int)strlen(str); i++) {
		if (str[i] == '0' || str[i] == '1' ||
				str[i] == '2' || str[i] == '3' ||
				str[i] == '4' || str[i] == '5' ||
				str[i] == '6' || str[i] == '7' ||
				str[i] == '8' || str[i] == '9')  {
		}
		else
			return 0;
	}
	return 1;
}

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

// Tell if a string has variable format
int isVar(char* str) {
	if (str[0] == '0' || str[0] == '1' ||
			str[0] == '2' || str[0] == '3' ||
			str[0] == '4' || str[0] == '5' ||
			str[0] == '6' || str[0] == '7' ||
			str[0] == '8' || str[0] == '9' ||
			isDelim(str[0] == 1))
		return 0;
	return 1;
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
	res[right - left + 1] = '\0';
	return res;
}

// Tell if string is a C key word
int isKey(char* str) {
	return (!strcmp(str, "int") || !strcmp(str, "float"));
}


// Reads a string and prints each token type
// char* str : input string (code from given file)
void parse(char* str) {
	printf("ORIGINAL LINE : %s\n", str);
	int left = 0;
	int right = 0;
	int len = strlen(str);

	while (right <= len - 1 && right >= left) { // stop when reach end of string or left cursor reaches right cursor

		if (!isDelim(str[right])) // extend right until end of "word"
			right++;
		if (isDelim(str[right]) && left == right) {
			if (isOpe(str[right]))
				printf("'%c' IS AN OPERATOR\n", str[right]);
			else
				printf("'%c' IS ?\n", str[right]);
			right++;
			left = right;
		} else if ((isDelim(str[right]) && left != right) || (right == len && left != right)) {
			char* sub = getSubString(str, left, right);
			int lastPos = strlen(sub) - 1;
			//if (isDelimNoSpace(sub[lastPos])) // remove delimiter in subString at last pos
			//	sub[lastPos] = '\0';
			sub[lastPos] = '\0';
			if (isKey(sub))
				printf("%s IS A KEY WORD\n", sub);
			else if (isInt(sub))
				printf("%s IS A INTEGER\n", sub);
			else if (isVar(sub))
				printf("%s IS A VARIABLE\n", sub);
			else
				printf("%s IS NOTHING YET\n", sub);
			left = right;
		}
	}
	if (str[len - 1] == ';')
		printf("'%c' IS END OF LINE\n", str[len - 1]);
}
