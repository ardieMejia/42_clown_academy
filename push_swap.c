

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>
#include <assert.h>






typedef struct Node
{
	int value;
	int norm_index;
}Node;


typedef struct MyStack
{
	int length;
	Node nodes[];
} MyStack;


int get_stack_minimum(MyStack *stack)
{
	int i = 0;
	int min_norm_index = stack->nodes[0].norm_index;
	while(i<stack->length){
		printf("\n what\n");
		if (min_norm_index > stack->nodes[i].norm_index)
			min_norm_index = stack->nodes[i].norm_index;
		i++;
	}
	return min_norm_index;
}


// int * ra(int stack_a[]){
// 	printf("\n we are rotating %d\n", stack_a[0]);
// }


int order(Node * nodes, int index1, int index2, int index3){
	if (nodes[0].value == index1 && nodes[1].value == index2 && nodes[2].value == index3)
	{
		return 1;
	}
	return 0;
}

// void sa(Node *nodes)
// {
// 	int temp = nodes[0].value;
// 	nodes[0].value = nodes[1].value;
// 	nodes[1].value = temp;
// }


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




void display(int stack_a[])
{
	printf("\n ================================================== \n");
	int i = 0;
	while(i < 10){
		printf("%d \n", stack_a[i]);
		i++;
	}
	printf("\n ================================================== \n");
}

void fill_values(MyStack * stackA, int * temp_array)
{	
	stackA->nodes[0].value = temp_array[0];
	stackA->nodes[1].value = temp_array[1];
	stackA->nodes[2].value = temp_array[2];
	stackA->nodes[3].value = temp_array[3];
	stackA->nodes[4].value = temp_array[4];
	stackA->nodes[5].value = temp_array[5];
	stackA->nodes[6].value = temp_array[6];
	stackA->nodes[7].value = temp_array[7];
	stackA->nodes[8].value = temp_array[8];
	stackA->nodes[9].value = temp_array[9];
	
	stackA->length = 10;
}

void fill_normIndex(MyStack * stackA)
{
	stackA->nodes[0].norm_index = 7;
	stackA->nodes[1].norm_index = 3;
	stackA->nodes[2].norm_index = 8;
	stackA->nodes[3].norm_index = 5;
	stackA->nodes[4].norm_index = 2;
	stackA->nodes[5].norm_index = 9;
	stackA->nodes[6].norm_index = 1;
	stackA->nodes[7].norm_index = 5;
	stackA->nodes[8].norm_index = 6;
	stackA->nodes[9].norm_index = 0;

}


int closerToTop(MyStack* current_stack, int current_norm_index){
	if (current_norm_index  < (int)(current_stack->length/ 2))
		return 1;
	return 0;			  
}

void append_to_list(char * list_of_operations, char * newString){
	strcat(list_of_operations, newString);
}



int ra(MyStack *stackA, int current_norm_index, int (*closerToTop) (MyStack*, int))
{
	int i = 0;
	int temp_norm_index = stackA->nodes[0].norm_index;
	int temp_value = stackA->nodes[0].value;
	if (closerToTop(stackA, current_norm_index) && stackA->nodes[0].norm_index != current_norm_index)
	{
		while(i < stackA->length - 1)
		{
			stackA->nodes[i].value = stackA->nodes[i+1].value;
			stackA->nodes[i].norm_index = stackA->nodes[i+1].norm_index;
			i++;
		}
		stackA->nodes[i].value = temp_value;
		stackA->nodes[i].norm_index = temp_norm_index;
		
	}
	// stackA->length--;
		
	return 0;
}

void while_each_item(MyStack *stackA, int current_index, char * list_of_operations){
	while(ra(stackA, current_index, closerToTop )){
		      append_to_list(list_of_operations, "ra");
      }
}

void while_more_than_3(MyStack *stackA, void (*while_each_item) (MyStack*, int, char *), char * list_of_operations){
	// int current_index = get_stack_minimum(stackA);
	int current_index = 0;
	printf("\n minimum index %d\n", current_index);


	int i = 0;
	// while(stackA->length > 9)
	while(i <10)
	{
		while_each_item(stackA, current_index, list_of_operations);
		// stackA->length--;//temp
		i++;

	}
}

int main (){

	
	static char * list_of_operations = NULL;
	
	MyStack *stackA = malloc(sizeof(MyStack) + (sizeof(Node)) * 10);
	int temp_array[] = {8, 4, 9, 5, 3, 10, 2, 6, 7, 1};
	fill_values(stackA, temp_array);
	fill_normIndex(stackA);
	
	// MyStack *stackB = malloc(sizeof(MyStack) + (sizeof(Node)) * 0);


	list_of_operations = malloc(sizeof(char) * 1);
	bzero(list_of_operations, 1);


	
	while_more_than_3(stackA, while_each_item, list_of_operations);




	printf("\n nodes[0] all values %d %d %d %d %d %d %d %d %d %d\n",
	       stackA->nodes[0].value,
	       stackA->nodes[1].value,
	       stackA->nodes[2].value,
	       stackA->nodes[3].value,
	       stackA->nodes[4].value,
	       stackA->nodes[5].value,
	       stackA->nodes[6].value,
	       stackA->nodes[7].value,
	       stackA->nodes[8].value,
	       stackA->nodes[9].value
		);
	

	return 0;
	
}


