#include "checker.h"

int isAssign(AstNode** listNode, int pos) {
	int size = sizeof(listNode) / sizeof(listNode[0]);
	if (!strcmp(listNode[pos + 4]->value, "="))
		return 1;
	return 0;
}

void check(AstNode** ListNode, int nbNode) {
	for (int i = 0; i < nbNode; i++)
	{
		switch (ListNode[i]->type) {
			case 0:		// Operator
				break;
			case 1:		// KeyWord
				if (isAssign(ListNode, i))
					printf("YES\n");
				break;
			case 2:		// Delimiter
				break;
			case 3:		// Variable
				break;
			case 4:		// Num
				break;
			case 5:		// ??
				break;

		}
		printf("%s", ListNode[i]->value);
	}	
	printf("\n");
}
