// 6515798 zy15798 Ziyi Gong
#include <stdio.h>
#include <limits.h>
#define FAILURE -1    // Used instead of EXIT_FAILURE as EXIT_FAILURE is defined as 1 on OS X.
#define SUCCESS 0     // Consistent with FAILURE.
#define CITY_NUM 9

int get_option();
int get_input(char prompt[], int upper_limit, char err[]);
int booking();
void available();

char cities[CITY_NUM][10] = {"Ningbo", "Hangzhou", "Suzhou", "Changzhou", "Shanghai", "Taizhou", "Wenzhou", "Jinhua", "Nanjing"};
// A three-dimensional array. First - origin; Second - destionation; Third - tickets or price.
int tickets[CITY_NUM][CITY_NUM][2] = {
    {{-1, 0}, {10, 100}, {-1, 0}, {-1, 0}, {-1, 0}, {10, 200}, {-1, 0}, {-1, 0}, {-1, 0}},
    {{10, 100}, {-1, 0}, {-1, 0}, {10, 100}, {10, 100}, {-1, 0}, {-1, 0}, {10, 100}, {10, 200}},
    {{-1, 0}, {-1, 0}, {-1, 0}, {10, 100}, {10, 100}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}},
    {{-1, 0}, {10, 100}, {10, 100}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {10, 100}},
    {{-1, 0}, {10, 100}, {10, 100}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}},
    {{10, 100}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {10, 300}, {-1, 0}, {-1, 0}},
    {{-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {10, 300}, {-1, 0}, {10, 100}, {-1, 0}},
    {{-1, 0}, {10, 100}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {10, 100}, {-1, 0}, {-1, 0}},
    {{-1, 0}, {10, 200}, {-1, 0}, {10, 100}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}}
};

int main()
{
	int user_input = 0;
	do
	{
		user_input = get_option();
        // 1 - book tickets; 2 - show avaiable tickers; 3 - quit.
		switch(user_input)
		{
			case 1:
				booking();
				break;
			case 2:
				available();
				break;
		}
	}while(user_input != 3);
    return 0;
}

int get_input(char *prompt, int upper_limit, char *err)
{
    // Gets inputs for the general purpose. Requires a prompt, an upper limit to find the range, and an error message in case of wrong inputs. Returns the input or FAILURE if the input is not in the range.
    int input;
    int cond;
    
    printf("%s", prompt);
    scanf("%d", &input);
    
    cond = (input <= upper_limit && input > 0);
    if(cond)
        return input;
    else
    {
        printf("%s", err);
        return FAILURE;
    }
}

int get_option()
{
    // Returns the option or FAILURE if no correct option has been received.
    printf("1) Book ticket(s)\n");
	printf("2) List available tickets\n");
	printf("3) Quit\n");

	return get_input("Enter option: ", 3, "Invalid option!\n");
}

int booking()
{
    // Returns run code (SUCCESS or FAILURE).
    int i, orig, dest, tick_num;
    
    // Prints out available stations.
    printf("Num\tStation\n");
    for(i = 0; i < CITY_NUM; i++)
        printf("%d\t%s\n", i + 1, cities[i]);
    
    // Gets and verifies stations.
    if((orig = get_input("Origin station number: ", CITY_NUM, "Invalid station number.\n")) == FAILURE)
        return FAILURE;
    if((dest = get_input("Destination station number: ", CITY_NUM, "Invalid station number.\n")) == FAILURE)
        return FAILURE;
    
    // Confirms the route.
    if(tickets[orig - 1][dest - 1][0] == -1)
    {
        printf("No train between %s and %s.\n", cities[orig -1], cities[dest - 1]);
        return FAILURE;
    }
    
    // Gets and verifies the number of tickets.
    if((tick_num = get_input("Number of tickets: ", INT_MAX, "Invalid number of tickets.\n")) == FAILURE)
        return FAILURE;
    
    // Booking.
    if(tickets[orig - 1][dest - 1][0] < tick_num)
    {
        printf("Not enough tickets available (%d requested, %d remaining).\n", tick_num, tickets[orig - 1][dest - 1][0]);
        return SUCCESS;
    }
    else
    {
        tickets[orig - 1][dest - 1][0] -= tick_num;
        printf("Tickets booked, total cost is %d RMB.\n", tick_num * tickets[orig - 1][dest - 1][1]);
        return SUCCESS;
    }
}

void available()
{
    //
    int i;
    
    //Prints out the header.
    for(i = 0; i < CITY_NUM; i++)
        printf("\t%.6s", cities[i]);
    puts("");
    
    // Prtins out the rest of the table
    for(i = 0; i < CITY_NUM; i++)
    {
        int j;
        
        printf("%.6s", cities[i]); // Prints out the other header.
        for(j = 0; j < CITY_NUM; j++) // Prints out the number of tickets.
            if(tickets[i][j][0] == -1)
                printf("\t");
            else
                printf("\t%d", tickets[i][j][0]);
        puts("");
    }
}