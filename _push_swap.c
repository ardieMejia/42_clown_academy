

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>
#include <assert.h>


#include "basic/test.h"
#include "basic/libinput_cleaner.h"
#include "libft/libft.h"










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


void fill_values(MyStack * stackA, int * temp_array, int length)
{
	int i = 0;
	stackA->length = length;
	while(i < stackA->length)
	{
		stackA->nodes[i].value = temp_array[i];
		i++;
	}

	
}


void base_swap(int * a, int * b){
	int temp = * a;
	* a = *b;
	*b = temp;
}

void prepare_values_array(int * temp_array, MyStack * stack){
	int i = 0;
	while( i < stack->length)
	{
		temp_array[i] = stack->nodes[i].value;
		i++;
	}
}






/*
  the ugliest function in the world
*/
void fill_normIndex(MyStack * stack)
{
	// stack->nodes[0].norm_index = 7;
	// stack->nodes[1].norm_index = 3;
	// stack->nodes[2].norm_index = 8;
	// stack->nodes[3].norm_index = 5;
	// stack->nodes[4].norm_index = 2;
	// stack->nodes[5].norm_index = 9;
	// stack->nodes[6].norm_index = 1;
	// stack->nodes[7].norm_index = 5;
	// stack->nodes[8].norm_index = 6;
	// stack->nodes[9].norm_index = 0;

	int * temp_array = malloc(sizeof(int) * stack->length);
	prepare_values_array(temp_array, stack);
	int i = 0;
	int start_point = 0;
	while(start_point < stack->length)
	{
		i = 0;
		while(i < stack->length)
		{
			if (temp_array[start_point] < temp_array[i])
				base_swap(&(temp_array[start_point]), &(temp_array[i]));
			i++;
		}
		start_point++;
	}



	i = 0;
	int j = 0;
	while(i < stack->length)
	{
		j=0;
		while(j < stack->length)
		{
			if (temp_array[j] == stack->nodes[i].value)
				stack->nodes[i].norm_index = j;
			j++;
		}
		i++;
	}

	free(temp_array);

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


void empty_stack_a(MyStack *stackA, int current_index, char * list_of_operations){
	while(ra(stackA, current_index, closerToTop )){
		      append_to_list(list_of_operations, "ra");
      }

}



int * get_list_of_numbers(char ** filtered_input_split, int length){
	int *test = (int * )malloc(sizeof(int) * length);
	// char * temp = NULL;

	printf("\n filtered_input_split %c\n", filtered_input_split[2][0]);
	int i = 0;
	while(i < length){
		test[i] = ft_atoi(filtered_input_split[i]);
		// int	ft_atoi(const char *nptr)
		i++;
	}


	i = 0;
	while(i < length){
		printf("\n list of numbers: %d\n", test[i]);
		i++;
	}
	return test;
}







void display_stack(MyStack * t_stacka)
{
	printf("\n ================================================== \n");
	int i = 0;
	while(i < t_stacka->length){
		printf("%d \n", t_stacka->nodes[i].value);
		i++;
	}
	printf("\n ================================================== \n");
}

int * get_list_of_fixed_numbers(int length){
	int *test = (int * )malloc(sizeof(int) * length);

	int i = 0;
	while(i < length){
		test[i] = 9;
		i++;
	}

	i = 0;
	while(i < length){
		printf("\n test: %d\n", test[i]);
		i++;
	}
	return test;
}

void display_stack_values(Stack *game_stack){
	Blob *current_blob_pointer = game_stack->stackA;
	while(current_blob_pointer){
		printf("\n [%d]: %d", (*current_blob_pointer).norm_index, (*current_blob_pointer).value);
		
		current_blob_pointer =  (*current_blob_pointer).next;
	}


}



void free_split_string(char ** split_string){
	int i = 0;
	if(split_string){
		while(split_string[i]){
			free(split_string[i]);
			i++;
		}
	}

	free(split_string);
}




int get_length_filtered_input(char * filtered_input)
{
	char ** numbers_with_spaces = ft_split(filtered_input, ' ');
	int i = 0;
	while(numbers_with_spaces[i]){
		i++;
	}


	printf("\n length %d\n", i);
	// free(numbers_with_spaces);
	free_split_string(numbers_with_spaces);
	return i;

}



void free_game(Stack *game_stack){
	Blob * tracker = game_stack->stackA;
	Blob * current = game_stack->stackA;
	
	while(tracker){
		tracker=current->next;
		free(current);
		current=tracker;
	}

	free(game_stack);
	game_stack=NULL;

	
}




int get_length_stack(Blob * stackA){
	int i = 0;
	while(stackA){
		stackA = stackA->next;
		i++;
	}
	return i;
}



// void base_swap(int * a, int * b){
void fill_norm_index(Stack * game_stack)
{

	int stack_a_length = get_length_stack(game_stack->stackA);
	int i ;
	int j ;
				  
	int * temp_array = malloc(sizeof(int) * stack_a_length );

	if (temp_array[0])
		printf("\n temp_arrat %d\n", temp_array[0]);

	i=0;
	Blob * current = game_stack->stackA;
	while(current){
		temp_array[i] = current->value;
		current = current->next;
		i++;
	}
	i=0;
	j=0;
	while(i < stack_a_length ){
		j=i;
		while ( j < stack_a_length){
			if (temp_array[i] > temp_array[j])
				base_swap(&(temp_array[i]), &(temp_array[j]));
			j++;
		}
		i++;
	}
	printf("\n temp_array %d\n", temp_array[0]);
	printf("\n temp_array %d\n", temp_array[1]);

	i=0;
	j=0;
	current = game_stack->stackA;
	while(i < stack_a_length)
	{
		current = game_stack->stackA;
		while(current){
			if(temp_array[i] == current->value)
				current->norm_index = i ;
			current = current->next;
		}
		i++;
	}

	printf("\n game_stack first norm_index (4 i think): %d\n", game_stack->stackA->norm_index);
	free(temp_array);
}







int main (){

	
	static char * list_of_operations;
	


	
	// MyStack *stackB = malloc(sizeof(MyStack) + (sizeof(Node)) * 0);


	list_of_operations = malloc(sizeof(char) * 1);
	bzero(list_of_operations, 1);








	// ==============================




	// char * filtered_input = (char *)malloc(sizeof(char) * 21);

	char * filtered_input = ft_strdup("5 4 3 2 1 10 9 6 7 8");
	
	if(!filtered_input)
		return 0;
	

	char ** filtered_input_split = ft_split(filtered_input, ' ');


	int filtered_input_length = get_length_filtered_input(filtered_input);
	printf("\n filtered_input %d\n", filtered_input_length);
	


	int *list_of_numbers = NULL;
	
	list_of_numbers = get_list_of_numbers(filtered_input_split, filtered_input_length);	
	

	// if(game_stack->stackA != NULL)
	// 	printf("\n %d\n", game_stack->stackA[0].value);

	Stack *game_stack = prepare_stack_values(list_of_numbers, filtered_input_length);



	
	#ifdef DEBUG
	display_stack_values(game_stack);
	test_me();
	#endif






	fill_norm_index(game_stack);

		
	program_output(list_of_operations)

	// print_all_moves();


	free(filtered_input);
	free(list_of_operations);
	free(list_of_numbers);
	free_split_string(filtered_input_split);
	free_game(game_stack);

	return 0; // hello there



	return 0;
	
}


