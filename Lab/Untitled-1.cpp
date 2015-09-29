#include <stdio.h>

int main()
{
	int intVal;
	char charVal;
	
	puts("enter a num and a char: ");
	scanf("%d", &intVal);
	charVal = getchar();
	printf("int: %d char: %c \n", intVal, charVal);
	return 0;
}