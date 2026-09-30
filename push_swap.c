

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>
#include <assert.h>








// int * ra(int stack_a[]){
// 	printf("\n we are rotating %d\n", stack_a[0]);
// }


int order(int * stack_a, int index1, int index2, int index3){
	if (stack_a[0] == index1 && stack_a[1] == index2 && stack_a[2] == index3)
	{
		return 1;
	}
	return 0;
}

void sa(int * stack_a)
{
	int temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
}


void add_to_op_list(char * list_of_operations, char * string_add)
{
	char * temp_list_of_operations = realloc(list_of_operations, (strlen(list_of_operations) + 4)); 
	int j = strlen(temp_list_of_operations);
	list_of_operations = temp_list_of_operations;
	list_of_operations[j] = string_add[0];
	list_of_operations[j+1] = string_add[1];
	list_of_operations[j+2] = ' ';
	list_of_operations[j+3] = '\0';
}


void sort_3_swap_and_append(int *stack_a, char * list_of_operations){

	if (order(stack_a, 2, 1, 3)){
		sa(stack_a);
		add_to_op_list(list_of_operations, "ra");
	}
	// int temp = stack_a[0];
	// stack_a[0] = stack_a[1];
	// stack_a[1] = temp;

		

}


void display(int stack_a[])
{
	printf("\n ================================================== \n");
	int i = 0;
	while(i < 3){
		printf("%d \n", stack_a[i]);
		i++;
	}
	printf("\n ================================================== \n");
}

int main (){
	static char * list_of_operations = NULL;
	int stack_a[] = {2, 1, 3};

	list_of_operations = malloc(sizeof(char) * 1);
	bzero(list_of_operations, 1);
	sort_3_swap_and_append(stack_a, list_of_operations);

	printf("\n list of op: %s\n", list_of_operations);

	printf("\n stack_a %d %d %d\n", stack_a[0], stack_a[1], stack_a[2]);

	return 0;
	
}


