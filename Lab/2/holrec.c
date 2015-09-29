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
		if(i == 0 || i == depth - 1)
		{
			for(j = 0; j < length; j++)
				printf("+");
			printf("\n");
		}
		else
		{
			for(j = 0; j < length; j++)
				if(j == 0 || j == length -1)
					printf("+");
				else
					printf(" ");
			printf("\n");
		}
	}
}