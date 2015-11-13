#include <stdio.h>

int prompt_input(char *prompt);

int main()
{
	int stud_num;
	int mark[stud_num = prompt_input("Enter number of marks: ")];
	
	// asks for marks of stud_num
	int i;
	for(i = 0; i < stud_num; i++)
	{
		mark[i] = prompt_input("Enter mark: ");
	}
	
	// sorts the marks
	for(i = 0; i < stud_num - 1; i++)
	{
		int j;
		for(j = i + 1; j < stud_num; j++)
		{
			if(mark[i] < mark[j])
			{
				int temp = mark[i];
				mark[i] = mark[j];
				mark[j] = temp;
			}
		}
	}
	
	// prints the marks
	for(i = 0; i < stud_num; i++)
		printf("%d\n", mark[i]);
	
	return 0;
}

int prompt_input(char *prompt)
{
	int inp;
	
	printf("%s", prompt);
	scanf("%d", &inp);
	return inp;
}