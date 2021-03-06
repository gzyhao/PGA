#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>

struct dept
{
	int id;
	char *name;
	int balance;
	struct dept *next;
};
typedef struct dept dept_t;

// Function declarations for each part of the assignment.
// For (a)
dept_t *create_dept(int dept_id, char *dept_name, int dept_balance);
// For (b)
dept_t *load_dept(int id);
// For (c)
void free_dept(dept_t *dept);
// For (d)
void print_dept(dept_t *dept);
// For (e)
void add_dept(dept_t **all_depts, dept_t *new_dept);
// For (f)
void load_all_depts(dept_t **all_depts, char *filename);
// For (g)
void free_all_depts(dept_t *all_depts);
// For (h)
dept_t *find_dept(dept_t *all_depts, char *dept_name);
// For (i)
void summary_for_dept(dept_t *all_depts, char *dept_name);
// For (j)
void generate_report(dept_t *all_depts);

// Extre functions needed
char *generate_filename(int id);
char *read_char_line(FILE *fp);
int read_int_line(FILE *fp);

// Implementations of each function.
// For (k)
int main(int argc, char *argv[])
{
}

// (a)
dept_t *create_dept(int dept_id, char *dept_name, int dept_balance)
{
	dept_t *new_dept_ptr;
	
	new_dept_ptr->id = dept_id;
	strcpy(new_dept_ptr->name, dept_name);
	new_dept_ptr->balance = dept_balance;
	new_dept_ptr->next = NULL;
	
	return new_dept_ptr;
}

// (b)
dept_t *load_dept(int id)
{
	char *filename = generate_filename(id);
	FILE *fp = fopen(filename, "r");
	if(fp == NULL)
	{
		perror("Cannot open the file: ");
		exit(EXIT_FAILURE);
	}
	free(filename);
	
	char *name;
	name = read_char_line(fp);
	
	int balance = 0;
	while(&fp != '\n')
		balance += read_int_line(fp);
	fclose(fp);
	
	dept_t *new_dept_ptr = create_dept(id, name, balance);
	free(name);
	
	return new_dept_ptr;
}

// For (c)
void free_dept(dept_t *dept)
{
	free(dept->name);
	free(dept);
}

// For (d)
void print_dept(dept_t *dept)
{
	
}

// For (e)
void add_dept(dept_t **all_depts, dept_t *new_dept)
{
}

// For (f)
void load_all_depts(dept_t **all_depts, char *filename)
{
}

// For (g)
void free_all_depts(dept_t *all_depts)
{
}   

// For (h)
dept_t *find_dept(dept_t *all_depts, char *dept_name)
{
}

// For (i)
void summary_for_dept(dept_t *all_depts, char *dept_name)
{
}

// For (j)
void generate_report(dept_t *all_depts)
{
}

char *generate_filename(int id)
{
	char *filename = malloc(sizeof(char) * 30);
	sprintf(id, "%d.txt", filename);
	realloc(filename, sizeof(char) * (strlen(filename) + 1));
	return filename;
}

char *read_char_line(FILE *fp);
{
	char ch;
	int cur_size = 12;
	char *str = malloc(sizeof(char) * cur_size);
	int cur_pos = 0;
	
	fscanf(fp, "%c", &ch);
	while(ch != '\n')
	{
		if(cur_pos = cur_size - 1)
		{
			cur_size *= 2;
			realloc(str, sizeof(char) * cur_size);
		}
		str[cur_pos] = ch;
		cur_pos++;
		fscanf(fp, "%c", &ch);
	}
	str[cur_pos] = '\0';
	
	return str;
}

int read_int_line(FILE *fp);
{
	char ch;
	int cur_size = 12;
	char *str = malloc(sizeof(char) * cur_size);
	int cur_pos = 0;
	int sign = 1;
	
	fscanf(fp, "%c", &ch);
	if(ch == '(')
		sign = -1;
	while(ch != '\n')
	{
		if(cur_pos = cur_size - 1)
		{
			cur_size *= 2;
			realloc(str, sizeof(char) * cur_size);
		}
		if(ch != '(' && ch != ')')
		{
			str[cur_pos] = ch;
			cur_pos++;
		}
		fscanf(fp, "%c", &ch);
	}
	str[cur_pos] = '\0';
	
	num = sign * atoi(str);
	free(str);
	return num;
}
