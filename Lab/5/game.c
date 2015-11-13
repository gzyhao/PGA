#include <stdio.h>

int ask_for_input();
void print_map();
void up();
void down();
void left();
void right();

char map[8][12] = {
	"##########\n",
	"#@.......#\n",
	"#........#\n",
	"#........#\n",
	"#........#\n",
	"#........#\n",
	"#........#\n",
	"##########\n"
};
int pos[2] = {1, 1};

int main()
{
	int opt;
	do{
		print_map();
		
		opt = ask_for_input();
		
		switch(opt)
		{
			case 8:
				up();
				break;
			
			case 2:
				down();
				break;
			
			case 4:
				left();
				break;
				
			case 6:
				right();
				break;
		}
	} while(opt != 0);
	
	return 0;
}

int ask_for_input()
{
	int inp;
	
	printf("8: Going up\n");
	printf("2: Going down\n");
	printf("4: Going left\n");
	printf("6: Going right\n");
	printf("0: Quit\n");
	printf("Your choice: ");
	scanf("%d", &inp);
	return inp;
}

void up()
{
	if(pos[0] < 2)
	{
		print_map();
		printf("Invalid move!\n");
	}
	else
	{
		map[pos[0]][pos[1]] = '.';
		pos[0] -= 1;
		map[pos[0]][pos[1]] = '@';
	}
}

void down()
{
	if(pos[0] > 5)
	{
		print_map();
		printf("Invalid move!\n");
	}
	else
	{
		map[pos[0]][pos[1]] = '.';
		pos[0] += 1;
		map[pos[0]][pos[1]] = '@';
	}
}

void left()
{
	if(pos[1] < 2)
	{
		print_map();
		printf("Invalid move!\n");
	}
	else
	{
		map[pos[0]][pos[1]] = '.';
		pos[1] -= 1;
		map[pos[0]][pos[1]] = '@';
	}
}
void right()
{
	if(pos[1] > 7)
	{
		print_map();
		printf("Invalid move!\n");
	}
	else
	{
		map[pos[0]][pos[1]] = '.';
		pos[1] += 1;
		map[pos[0]][pos[1]] = '@';
	}
}

void print_map()
{
	int i;
	for(i = 0; i < 8; i++)
		printf("%s", map[i]);
}