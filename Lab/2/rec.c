#include <stdio.h>

int main()
{
	int i, j;
	int length, depth;

	printf("enter the length: ");
	scanf("%d", &length);
	
	printf("enter the depth: ");
	scanf("%d", &depth);
	
	for(i = 0; i < depth; i++)
	{
		for(j = 0; j < length; j++)
			printf("+");
		printf("\n");
	}
}