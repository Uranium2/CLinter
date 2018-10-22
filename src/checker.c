#include "checker.h"

int isAssign(Token **listToken, int pos)
{
	//int size = sizeof(listToken) / sizeof(listToken[0]);
	if (!strcmp(listToken[pos + 4]->value, "="))
		return 1;
	return 0;
}

void check(Token **listToken, int nbNode)
{
	for (int i = 0; i < nbNode; i++)
	{
		switch (listToken[i]->type)
		{
		case 0: // Operator
			break;
		case 1: // KeyWord
			if (isAssign(listToken, i))
				//printf("YES\n");
				break;
		case 2: // Delimiter
			break;
		case 3: // Variable
			break;
		case 4: // Num
			break;
		case 5: // ??
			break;
		}
		printf("%s|", listToken[i]->value);
	}
	printf("\n");
}
