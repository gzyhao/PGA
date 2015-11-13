// 6515798 zy15798 Ziyi Gong
#include <stdio.h>
#include <stdlib.h>

int get_input();
void print_bigdogs_for(int n);
void print_bigdogs_while(int n);

int main(int argc, char *argv[]){
	int upper_limit;
	// takes an input and eliminates wrong ones.
	if((upper_limit = get_input()) < 2){
		printf("Invalid upper limit!\n");
		return EXIT_FAILURE;
	}
	printf("1");
	// diff implementation
	print_bigdogs_for(upper_limit);    // shorter
//	print_bigdogs_while(upper_limit);    // more interesting
	puts("");    // print a new line to make things tidy
	return 0;
}

int get_input(){
	// asks the user for an upper limit, and returns it as an int.
	int input;
	printf("Enter upper limit: ");
	scanf("%d", &input);
	return input;
}

void print_bigdogs_for(int limit){
	// takes an upper limit, and prints the table of results up to the limit in the designated format.
	int i;
	for(i = 2; i <= limit; i++){
        if(((i - 1) % 10) == 0)
			printf("\n");
		else
			printf("\t");
		if((i % 3) == 0 && (i % 7) == 0)
			printf("bigdog");
		else if((i % 3) == 0)
			printf("big");
        else if((i % 7) == 0)
            printf("dog");
        else
            printf("%d", i);
	}
}

void print_bigdogs_while(int limit){
	// the same as print_bigdogs_for but uses a diff method.
	int i = 1;
	while(++i <= limit){
		// uses the same method as of calculating the permission.
		int counter = 0;
		if((i % 3) == 0)
			counter += 3;
		if((i % 7) == 0)
			counter += 7;
		if(((i - 1) % 10) == 0)
			counter += 1;
		switch(counter){
			case 1:
				printf("\n%d", i);
				break;
			case 3:
				printf("\tbig");
				break;
			case 4:
				printf("\nbig");
				break;
			case 7:
				printf("\tdog");
				break;
			case 8:
				printf("\ndog");
				break;
			case 10:
				printf("\tbigdog");
				break;
			case 11:
				printf("\nbigdog");
				break;
			default:
				printf("\t%d", i);
				break;
		}
	}
}