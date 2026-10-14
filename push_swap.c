

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>
#include <assert.h>


#include "libstructutils/libfillstruct.h"
#include "libstructutils/libfilterinput.h"
#include "libstructutils/test.h"
#include "getters/libgetters.h"
#include "libft/libft.h"
#include "libstructutils/libfree.h"










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
		printf("\n A[%d]: %d  ", (*current_blob_pointer).norm_index, (*current_blob_pointer).value);
		current_blob_pointer =  (*current_blob_pointer).next;
	}

	current_blob_pointer = game_stack->stackB;
	while(current_blob_pointer){

		printf("\n B[%d]: %d  ", (*current_blob_pointer).norm_index, (*current_blob_pointer).value);
		current_blob_pointer =  (*current_blob_pointer).next;
	}
}

void display_stack_index(Stack *game_stack){

	Blob *current_blob_pointer = game_stack->stackA;
	
	while(current_blob_pointer){
		printf("\n A id[%d]: %d  ", current_blob_pointer->norm_index, get_index_from_norm(game_stack->stackA, current_blob_pointer->norm_index));
		current_blob_pointer =  current_blob_pointer->next;
	}

	current_blob_pointer = game_stack->stackB;
	while(current_blob_pointer){

		printf("\n B id[%d]: %d  ", current_blob_pointer->norm_index, get_index_from_norm(game_stack->stackB, current_blob_pointer->norm_index));
		current_blob_pointer =  current_blob_pointer->next;
	}
}

void display_stack_operations(char * list_of_operations){


	// char * test = strdup("hallsd\nlsd");
	// char * test = ft_strdup("hallsd\nlsd");

	

	// list_of_operations[2] = 's';

	// write(int __fd, const void *__buf, size_t __n);
	write(0,list_of_operations , ft_strlen(list_of_operations));
		
}

void display_stack_cost(Stack *game_stack){

	Blob *current_blob_pointer = game_stack->stackA;
	
	while(current_blob_pointer){
		printf("\n A cost[%d]: %d  ", (*current_blob_pointer).norm_index, (*current_blob_pointer).cost);
		current_blob_pointer =  (*current_blob_pointer).next;
	}

	current_blob_pointer = game_stack->stackB;
	while(current_blob_pointer){

		printf("\n B cost[%d]: %d  ", (*current_blob_pointer).norm_index, (*current_blob_pointer).cost);
		current_blob_pointer =  (*current_blob_pointer).next;
	}
}












// void base_swap(int * a, int * b){
void fill_norm_index(Stack * game_stack)
{

	int stack_a_length = get_stack_length(game_stack->stackA);
	int i ;
	int j ;
				  
	int * temp_array = malloc(sizeof(int) * stack_a_length );

	// if (temp_array[0])
	// 	printf("\n temp_arrat %d\n", temp_array[0]);

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
	// printf("\n temp_array %d\n", temp_array[0]);
	// printf("\n temp_array %d\n", temp_array[1]);

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

	// printf("\n game_stack first norm_index (4 i think): %d\n", game_stack->stackA->norm_index);
	free(temp_array);
}



char * pb(Stack * game_stack, char * list_of_operations)
{
	if (!game_stack->stackA)
		return NULL;
	Blob * temp_blob = game_stack->stackA;
	game_stack->stackA = game_stack->stackA->next;
	temp_blob->next = game_stack->stackB;
	game_stack->stackB = temp_blob;


	// list_of_operations = ft_strjoin(list_of_operations, " pb");
	
	list_of_operations = ft_strjoin(list_of_operations, "pb\n");
	return list_of_operations;
}

char * push_2_to_b(Stack * game_stack, char * list_of_operations){

	list_of_operations =  pb(game_stack, list_of_operations);
	list_of_operations =  pb(game_stack, list_of_operations);
	return list_of_operations;

	// printf("\n what now %d\n", game_stack->stackB->value);

}









void while_more_than_3(Stack * game_stack)
{
	// int amount_to_calculate = 2;
	fill_latest_cost(game_stack);
	Blob * candidate_from_A = game_stack->stackA;
	Blob * candidate_from_B = game_stack->stackB;

	get_lowest_cost(game_stack, candidate_from_A, candidate_from_B);
	printf("\n PRINTTTT\n");
	printf("\n we are not doing anthing\n");
	candidate_from_A = NULL;
	candidate_from_B = NULL;
}





int main (int argc, char **argv){







	static char * list_of_operations;
	char * filtered_input = NULL;
	Method method;


	Stack *game_stack;
	int * list_of_numbers;

	if(argc == 1){
		printf("\n no arguments\n");
		return 0;
	}
	
	// MyStack *stackB = malloc(sizeof(MyStack) + (sizeof(Node)) * 0);


	// list_of_operations = malloc(sizeof(char) * 2);
	list_of_operations = ft_strdup("");






	// ==============================



	method = SIMPLE;

	list_of_numbers = NULL;

#ifdef DEBUG
	method = COMPLEX;

	printf("\n argc %d\n", argc);
	printf("\n argv %d\n", *argv[0]);
	printf("\n method %d\n", method);
	list_of_numbers = malloc(sizeof(int) * 10);
	list_of_numbers[0]= 5;
	list_of_numbers[1]= 4;
	list_of_numbers[2]= 3;
	list_of_numbers[3]= 2;
	list_of_numbers[4]= 1;
	list_of_numbers[5]= 10;
	list_of_numbers[6]= 9;
	list_of_numbers[7]= 6;
	list_of_numbers[8]= 7;
	list_of_numbers[9]= 8;
	// filtered_input = ft_strdup("5 4 3 2 1 10 9 6 7 8");

#else


	if (!is_valid_input(&argc, argv, &list_of_numbers, &method))
	{
		printf("\n Error\n");

		return 1;
	}

#endif


	
	// if(!filtered_input){
	// 	printf("\n oop\n");
	// }


	
	game_stack = init_stack();
	fill_stack_values(game_stack, list_of_numbers, argc);

	fill_latest_cost(game_stack);



	
	#ifdef DEBUG
	display_stack_values(game_stack);
	test_me();
	#endif









	fill_norm_index(game_stack);






	list_of_operations = push_2_to_b(game_stack, list_of_operations);

	



	while_more_than_3(game_stack);

	display_stack_operations(list_of_operations);



#ifdef DEBUG
	display_stack_cost(game_stack);
	display_stack_values(game_stack);
	display_stack_index(game_stack);
	test_me();
#endif
	
	free(filtered_input);
	free(list_of_numbers);
	free(list_of_operations);


	free_game(game_stack);


	
	// free(argv);
	return 0;	





		
	// program_output(list_of_operations)

	// print_all_moves();




	




	return 0;
	
}


