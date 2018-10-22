#include "parser.h"

// Tell if a string is an Number
int isNum(char* str) {
	if (str == NULL)
		exit_m("isNum: str == NULL");
	int len = strlen(str);
	if (len <= 0)
		return 0;
	char* end;
	strtod(str, &end);
	if (end == str)
		return 0;
	if (strlen(end) > 0)
		return 0;
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
	return (isspace(c) || c == ';' ||
			c == '[' || c == ']' ||
			c == '(' || c == ')' ||
			c == '{' || c == '}'||
			c == ',' || c == '"' ||
			c == '\'' || isOpe(c));
}

// Tell if char is a delimiter expect space ' '
int isDelimNoSpace(char c) {
	if (c == ' ')
		return 0;
	return (c == ';' ||
			c == '[' || c == ']' ||
			c == '(' || c == ')' ||
			c == '{' || c == '}' ||
			c == '\t' || c == '"' ||
			c == '\'' || isOpe(c));
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
	return (!strcmp(str, "int") || !strcmp(str, "float") ||
			!strcmp(str, "double") || !strcmp(str, "char") ||
			!strcmp(str, "if") || !strcmp(str, "else") ||
			!strcmp(str, "while") || !strcmp(str, "do") ||
			!strcmp(str, "for") || !strcmp(str, "unsigned") ||
			!strcmp(str, "break") || !strcmp(str, "continue") ||
			!strcmp(str, "switch") || !strcmp(str, "return") ||
			!strcmp(str, "case") || !strcmp(str, "short") ||
			!strcmp(str, "static") || !strcmp(str, "void") ||
			!strcmp(str, "struct"));
}

int canBeExpe(char c, char* str, int right) {
	return isDelim(c) && (str[right - 1] == 'e' || str[right - 1] == 'E' ) && isdigit(str[right - 2]) && isdigit(str[right + 1]);
}

// Reads a string and prints each token type
// char* str : input string (code from given file)
void parse(char* str, int nbLine) {
	//printf("ORIGINAL LINE : %s", str);
	int left = 0;
	int right = 0;
	int len = strlen(str);
	Token** listToken = malloc(sizeof(Token) * len);
	int countList = 0;

	while (right <= len - 1 && right >= left) { // stop when reach end of string or left cursor reaches right cursor
		char* cString = malloc(sizeof(char));
		cString[0] = str[right];
		cString[1] = '\0';
		if (!isDelim(str[right])) // extend right until end of "word"
			right++;
		if (str[right] == '\"') {
			right++;
			while (1) {
				if (str[right] != '\"')
					right++;
				else if (str[right] == '\"' && str[right - 1] == '\\')
						right++;
					else if (str[right] == '\"') {
						right++;
						break;
					} else
						break;
				//printf("%c\n", str[right]);
				
			}
		}
		if (isDelim(str[right]) && left == right) {
			if (isOpe(str[right])) {
				listToken[countList] = createToken(Operator, cString);
				//printf("'%c' is an " MAG "OPERATOR\n" RESET, c);
			}
			else {
				listToken[countList] = createToken(Delimiter, cString);
				//printf("'%c' is a " GRN "DELIMITER\n" RESET, c);
			}
			right++;
			countList++;
			left = right;
		} else if ((isDelim(str[right]) && left != right) || (right == len && left != right)) {
			if (canBeExpe(str[right], str, right)) // is exponential ?
			{
				right++;
				continue;
			}
			char* sub = getSubString(str, left, right);
			int lastPos = strlen(sub) - 1;
			sub[lastPos] = '\0'; // remove \n at each end of lines
			if (sub[0] == '\0')
				continue;
			else if (isKey(sub)) {
				listToken[countList] = createToken(KeyWord, sub);
				//printf("'%s' is a " YEL "KEY WORD\n" RESET, sub);
			}
			else if (isNum(sub)) {
				listToken[countList] = createToken(Numerical, sub);
				//printf("'%s' is an " BLU "NUMBER\n" RESET, sub);
			}
			else if (isVar(sub)) {
				listToken[countList] = createToken(Variable, sub);
				//printf("'%s' is a " CYN "VARIABLE\n" RESET, sub);
			}
			else {
				listToken[countList] = createToken(Nothing, sub);
				//printf("'%s' " RED "IS NOTHING YET. at %d:%d\n" RESET, sub, nbLine, right);
			}
			left = right;
			countList++;
		}
	}
	check(listToken, countList);
}
