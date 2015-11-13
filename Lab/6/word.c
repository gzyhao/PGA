#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_num(char *prompt);
void get_words(char *words[], int num);
void game(char *word);
char *getstr();
int wordcmp(char *inp, char *word);

int main(){
	int num_words = get_num("Enter the number of words: ");
	char *words[num_words];
	
	// get the word list
	get_words(words, num_words);
	
	do
	{
		game(words[rand() % num_words]);
	} while(get_num("Wanna play again? 1 for yes, 0 for no: "));
}

int get_num(char *prompt)
{
	// asks for the user to give a number with the prompt given.
	int inp;
	char x;
	
	printf("%s", prompt);
	scanf("%d%c", &inp, &x);
	return inp;
}

void get_words(char *words[], int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		printf("Enter word: ");
		words[i] = getstr();
	}
}

void game(char *word)
{
	int num_char = strlen(word);
	int num_lives = 5;
	int corr_char[num_char];
	int correct = 0;
	
	int i;
	for(i = 0; i < num_char; i++)
		corr_char[i] = 0;
	
	do
	{
		char *inp;
		
		printf("Word:");
		for(i = 0; i < num_char; i++)
			if(corr_char[i] == 0)
				printf(" _");
			else
				printf(" %c", word[i]);
		printf("\n\n");
		
		printf("Guess (%d lives remaining): ", num_lives);
		inp = getstr();
		
		i = wordcmp(inp, word); // Flawed!!! Can't handle repetitive characters in one word!!!
		if(i == -1)
			correct = -1;
		else if(i < num_char)
		{
			corr_char[i] += 1;
			if(corr_char[i] == 1)
				correct += 1;
		}
		else
			num_lives -= 1;
		
		free(inp);
	} while(!(correct == num_char || correct == -1 || num_lives == 0));
	
	if(num_lives == 0)
		printf("Imbecile!\n");
	else
		printf("Correct!\n");
}

char *getstr()
{
	char c;
	int curr_len = 2;
	int curr_pos = 0;
	char *string = malloc(sizeof(char) * curr_len);
	while((c = getchar()) != '\n')
	{
		if(curr_pos < curr_len - 1)
			string[curr_pos] = c;
		else
		{
			curr_len *= 2;
			char *temp = malloc(sizeof(char) * curr_len);
			strcpy(temp, string);
			temp[curr_pos] = c;
			free(string);
			string = temp;
		}
		curr_pos += 1;
	}
	string[curr_pos] = '\0';
	return string;
}

int wordcmp(char *inp, char *word)
{
	if(strcmp(inp, word) == 0)
		return -1;
	
	int i;
	for(i = 0; i < strlen(word); i++)
		if(inp[0] == word[i])
			return i;
	
	return i;
}