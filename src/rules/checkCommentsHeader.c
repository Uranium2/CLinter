/**
* @file checkCommentsHeader.c
* @brief This c file will apply the checkCommentsHeader rule.
* @author Antoine TAVERNIER. New file created by Théo Huchard on 03/12/2018
* @date 16/11/2018
*/

#include "checkCommentsHeader.h"
#include "../tools/tool.h"

/**
 * @brief Check the rule comments-header
 * @param listToken List of Tokens
 * @param nbToken number of Tokens
 * @param line Line in the file
 * @param status State of comment header. 0 no comment. 1 Only opening Comment. 2 closed Comment
 * @param lastLine Helps to trigger the warning message at end of file
 * @param fileName File name we are working on
 */
void checkCommentsHeader(Token **listToken, int nbToken, int line, char *fileName, int *status, int lastLine)
{
    if (line - 1 == lastLine && *status < 2)
    {
        print_warning("Missing header", 1, 0, fileName);
        return;
    }
    if (line > 5 || *status > 1)
        return;
    for (int i = 0; i < nbToken; i++)
    {
        if (*status == 0 && listToken[i]->type == Comment)
            *status = *status + 1;
        else if (*status == 1 && strcmp(listToken[i]->value, "*/") < 0)
            *status = *status + 1;
    }
}