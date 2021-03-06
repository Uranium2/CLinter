/**
* @file parser.c
* @brief This c file will contain all functions to parse a file.
*
* @author Antoine TAVERNIER
*
* @date 16/11/2018
*/
#include "parser.h"

/**
 * @brief Tell if char is an operator
 * 
 * @param c character to check
 * @return int 0 false else true
 */
int isOpe(char c)
{
    return (c == '=' || c == '+' ||
            c == '-' || c == '*' ||
            c == '^' || c == '%' ||
            c == '>' || c == '<' ||
            c == '/' || c == '!' ||
            c == '&');
}

/**
 * @brief Tell if char is a delimiter + operator
 * 
 * @param c character to check
 * @return int 0 false else true
 */
int isDelim(char c)
{
    return (isspace(c) || c == ';' ||
            c == '[' || c == ']' ||
            c == '(' || c == ')' ||
            c == '{' || c == '}' ||
            c == ',' || c == '"' ||
            c == '\'' || c == '@' ||
            isOpe(c));
}

/**
 * @brief Tell if char is a delimiter expect space ' '
 * 
 * @param c character to check
 * @return int 0 false else true
 */
int isDelimNoSpace(char c)
{
    if (c == ' ')
        return 0;
    return (c == ';' ||
            c == '[' || c == ']' ||
            c == '(' || c == ')' ||
            c == '{' || c == '}' ||
            c == '\t' || c == '"' ||
            c == '\'' || isOpe(c));
}

/**
 * @brief Get subString of str delimited by left and right
 * 
 * @param str String containing text
 * @param left Left pointer on the str
 * @param right Right pointer on the str
 * @return char* Substring between left and right pointers
 */
char *getSubString(char *str, int left, int right, Collector *c)
{
    if (left > right)
        exit_m("getSubString: left > right");
    if (str == NULL)
        exit_m("getSubString: str == NULL");
    char *res = malloc_collect(c, sizeof(char) * (right - left + 2));
    int i = left;
    for (; i < right + 1; i++)
    {
        res[i - left] = str[i];
    }
    res[right - left + 1] = '\0';
    return res;
}

/**
 * @brief check if expression looks like an exponent format. Thus pushing the right pointer
 * 
 * @param c given char
 * @param str String containing text
 * @param right Right pointer on the str
 * @return int 0 false else true
 */
int canBeExpe(char c, char *str, int right)
{
    return isDelim(c) && (str[right - 1] == 'e' || str[right - 1] == 'E') && isdigit(str[right - 2]) &&
           isdigit(str[right + 1]);
}

/**
 * @brief Try to catches a comment block
 * 
 * @param right Right pointer on the str
 * @param str String containing text
 * @return int 0 false else true
 */
void checkCommentBlock(int *left, int *right, char *str, Token **listToken, int *countList, int *inComment, Collector *c)
{
    if (*inComment == 1)
    {
        *inComment = 0;
        while (!(str[*right] == '*' && str[*right + 1] == '/'))
        {
            if (str[*right + 1] == '\0')
            {
                *inComment = 1;
                break;
            }
            (*right)++;
        }
        *right = *right + 1;
        char *sub = getSubString(str, *left, *right, c);
        listToken[*countList] = createToken(Comment, sub, *left, c);
        *right = *right + 1;
        *countList = *countList + 1;
        *left = *right;
    }

    if (str[*right] == '/' && str[*right + 1] == '*') // comment block /* */
    {
        *inComment = 1;
        int tmp = 0;
        while (!(str[*right] == '*' && str[*right + 1] == '/'))
        {
            if (str[*right + 1] == '\0')
            {
                tmp++;
                break;
            }
            (*right)++;
        }
        if (tmp)
            *inComment = 1;
        else
            *inComment = 0;
        char *sub = getSubString(str, *left, *right, c);
        listToken[*countList] = createToken(Comment, sub, *left, c);
        *right = *right + 1;
        *countList = *countList + 1;
        *left = *right;
    }
}

/**
 * @brief Make the rest of a strinf one token of type 'Nothing'
 * 
 * @param right Right pointer on the str
 * @param left Left pointer on the str
 * @param str String containing text
 * @param nbNodes Number of tokens in listToken (local calculated value)
 * @param listToken List of tokens
 * @param countList Number of tokens in listToken
 */
void commentLine(int *right, int *left, char *str, int *nbNodes, Token **listToken, int *countList, Collector *c)
{
    while (str[*right] != '\0')
        *right = *right + 1;
    char *sub = getSubString(str, *left, *right, c);
    listToken[*countList] = createToken(Comment, sub, *left, c);
    *countList = *countList + 1;
    *nbNodes = *countList;
}

/**
 * @brief Reads a string and prints each token type
 * 
 * @param str input string (code from given file)
 * @param nbNodes number of nodes in string
 * @return Token** list of list of tokens
 */
Token **parse(char *str, int *nbNodes, int *inComment, Collector *c)
{
    int left = 0;
    int right = 0;
    int len = strlen(str);
    Token **listToken = malloc_collect(c, sizeof(Token) * len);
    int countList = 0;

    if (*inComment == 1)
        checkCommentBlock(&left, &right, str, listToken, &countList, inComment, c);

    while (right <= len - 1 && right >= left)
    {
        // stop when reach end of string or left cursor reaches right cursor
        char *cString = malloc_collect(c, sizeof(char));
        cString[0] = str[right];
        cString[1] = '\0';
        checkCommentBlock(&left, &right, str, listToken, &countList, inComment, c);
        if (str[right] == '/' && str[right + 1] == '/') // comment line
        {
            commentLine(&right, &left, str, nbNodes, listToken, &countList, c);
            assignTypes(listToken, *nbNodes);
            return listToken;
        }

        while (!isDelim(str[right]) && str[right] != '\0') // extend right until end of "word"
            right++;
        if (str[right] == '\0') // end of line
        {
            listToken[countList] = createToken(Nothing, cString, left, c);
            countList++;
            *nbNodes = countList;
            assignTypes(listToken, *nbNodes);
            return listToken;
        }
        if (str[right] == '\"')
        {
            right++;
            while (1)
            {
                if (str[right] != '\"')
                    right++;
                else if (str[right] == '\"' && str[right - 1] == '\\')
                    right++;
                else if (str[right] == '\"')
                {
                    right++;
                    break;
                }
                else
                    break;
            }
        }
        if (isDelim(str[right]) && left == right)
        {
            listToken[countList] = createToken(Nothing, cString, left, c);
            right++;
            countList++;
            left = right;
        }
        else if ((isDelim(str[right]) && left != right) || (right == len && left != right))
        {
            if (canBeExpe(str[right], str, right)) // is exponential ?
            {
                right++;
                continue;
            }
            char *sub = getSubString(str, left, right, c);
            int lastPos = strlen(sub) - 1;
            sub[lastPos] = '\0'; // remove \n at each end of lines
            if (sub[0] == '\0')
                continue;
            listToken[countList] = createToken(Nothing, sub, left, c);
            left = right;
            countList++;
        }
    }
    *nbNodes = countList;

    //Function to merge some tokens and assign good types?
    assignTypes(listToken, *nbNodes);
    return listToken;
}