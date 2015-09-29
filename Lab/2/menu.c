#include <stdio.h>
#include <stdlib.h>

int ask_for_option();
void ask_for_nums();
void addition();
void multi();
void mod();

static int input[2];

int main()
{
	int option = ask_for_option();
	while(option != 4)
	{
		if(option == 1)
			addition();
		else if (option == 2)
			multi();
		else if (option == 3)
			mod();
		option = ask_for_option();
	}
}

int ask_for_option()
{
	int input;
	printf("1: Add two numbers\n");
	printf("2: Multiply two numbers\n");
	printf("3: Calculate the modulus\n");
	printf("4: Quit\n");
	printf("Please enter a number: ");
	scanf("%d", &input);
	return input;
}

void ask_for_nums()
{
	input[0] = input[1] = 0;
	
	printf("Please enter a number: ");
	scanf("%d", &input[0]);
	
	printf("Please enter another number: ");
	scanf("%d", &input[1]);
}

void addition()
{
	printf("Addition\n");
	ask_for_nums();
	
	printf("%d\n", input[0] + input[1]);
}

void multi()
{
	printf("Multiplication\n");
	ask_for_nums();
	
	printf("%d\n", input[0] * input[1]);
}

void mod()
{
	printf("Modulus\n");
	ask_for_nums();
	
	printf("%d\n", input[0] % input[1]);
}