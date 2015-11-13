#include <stdio.h>

int prompt_input(char *prompt, char *var);
int prompt_input_num(char *prompt);

int main()
{
	
}

int prompt_input(char *prompt, char *var)
{
	int inp;
	
	printf("%s", prompt);
	scanf("%d", &inp);
	return inp;
}

int prompt_input_num(char *prompt)
{
	return prompt_input(prompt, &'');
}