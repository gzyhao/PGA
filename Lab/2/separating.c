#include <stdio.h>

void aLittleHelper(int inp);

int main()
{
    int temp;
    printf("pls enter a whole number: ");
    scanf("%d", &temp);
    aLittleHelper(temp);
	puts("");
    return 0;
}

void aLittleHelper(int inp)
{
    if (inp != 0)
    {
        aLittleHelper(inp / 10);
        printf("%d\t", inp % 10);
    }
}