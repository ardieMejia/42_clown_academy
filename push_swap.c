
 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>
#include <assert.h>


#include "libstructutils/libfillstruct.h"
#include "libstructutils/libfilterinput.h"
#include "libstructutils/libdebug.h"
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




// int ra(MyStack *stackA, int current_norm_index, int (*closerToTop) (MyStack*, int))
// {
// 	int i = 0;
// 	int temp_norm_index = stackA->nodes[0].norm_index;
// 	int temp_value = stackA->nodes[0].value;
// 	if (closerToTop(stackA, current_norm_index) && stackA->nodes[0].norm_index != current_norm_index)
// 	{
// 		while(i < stackA->length - 1)
// 		{
// 			stackA->nodes[i].value = stackA->nodes[i+1].value;
// 			stackA->nodes[i].norm_index = stackA->nodes[i+1].norm_index;
// 			i++;
// 		}
// 		stackA->nodes[i].value = temp_value;
// 		stackA->nodes[i].norm_index = temp_norm_index;
		
// 	}
// 	// stackA->length--;
		
// 	return 0;
// }












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
		printf("\n A[%d]: %d  ", current_blob_pointer->norm_index, current_blob_pointer->value);
		current_blob_pointer =  current_blob_pointer->next;
	}

	current_blob_pointer = game_stack->stackB;
	while(current_blob_pointer){

		printf("\n B[%d]: %d  ", current_blob_pointer->norm_index, current_blob_pointer->value);
		current_blob_pointer =  current_blob_pointer->next;
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


int rra(Stack * game_stack){
	if (!game_stack->stackA){
		return 1;
	}

	Blob * temp_last_blob = get_last_blob(game_stack->stackA);
	Blob * temp_next_to_last_blob = get_next_to_last_blob(game_stack->stackA);
	temp_last_blob->next = game_stack->stackA;
	game_stack->stackA = temp_last_blob;
	temp_next_to_last_blob->next = NULL;
	
	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "rra\n");

	temp_last_blob = NULL;
	temp_next_to_last_blob = NULL;
	return 0;
}

int rrb(Stack * game_stack){
	if (!game_stack->stackB){
		return 1;
	}

	Blob * temp_last_blob = get_last_blob(game_stack->stackB);
	Blob * temp_next_to_last_blob = get_next_to_last_blob(game_stack->stackB);
	temp_last_blob->next = game_stack->stackB;
	game_stack->stackB = temp_last_blob;
	temp_next_to_last_blob->next = NULL;

	
	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "rrb\n");

	temp_last_blob = NULL;
	temp_next_to_last_blob = NULL;
	return 0;
}

int ra(Stack * game_stack){
	if (!game_stack->stackA)
		return 1;
	if (get_stack_length(game_stack->stackA) == 1)
		return 0;
	
	Blob * old_head = game_stack->stackA;
	Blob * new_head = game_stack->stackA->next;
	Blob * last_blob = get_last_blob(game_stack->stackA);
	last_blob->next = old_head;
	old_head->next = NULL;
	game_stack->stackA = new_head;


	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "ra\n");

	old_head = NULL;
	new_head = NULL;
	last_blob = NULL;
	return 0;
}

int rb(Stack * game_stack){
	if (!game_stack->stackB)
		return 1;
	if (get_stack_length(game_stack->stackB) == 1)
		return 0;
	
	Blob * old_head = game_stack->stackB;
	Blob * new_head = game_stack->stackB->next;
	Blob * last_blob = get_last_blob(game_stack->stackB);
	last_blob->next = old_head;
	old_head->next = NULL;
	game_stack->stackB = new_head;


	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "rb\n");

	old_head = NULL;
	new_head = NULL;
	last_blob = NULL;
	return 0;
}


int pb(Stack * game_stack)
{
	if (!game_stack->stackA){
		return 1;
	}

	Blob * temp_blob = game_stack->stackA;
	game_stack->stackA = game_stack->stackA->next;
	temp_blob->next = game_stack->stackB;
	game_stack->stackB = temp_blob;

	temp_blob = NULL;
	
	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "pb\n");
	return 0;
}

int pa(Stack * game_stack)
{
	if (!game_stack->stackB){
		return 1;
	}

	Blob * temp_blob = game_stack->stackB;
	game_stack->stackB = game_stack->stackB->next;
	temp_blob->next = game_stack->stackA;
	game_stack->stackA = temp_blob;

	temp_blob = NULL;
	
	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "pb\n");
	return 0;
}


int rr_norm_index_check(Stack *game_stack){
	if (!game_stack->stackA || !game_stack->stackB){
		return 1;
	}


	/**
	we push this to its own interfae
	we push this to its own interfae
	we push this to its own interfae
	*/
	Blob * last_a_blob = game_stack->stackA;
	while (last_a_blob->next != NULL)
	{
		last_a_blob = last_a_blob->next;
	}
	Blob * last_b_blob = game_stack->stackB;
	while (last_b_blob->next != NULL)
	{
		last_b_blob = last_b_blob->next;
	}


	if(get_stack_length(game_stack->stackA) != 1){		
		Blob * temp_blob = game_stack->stackA;
		game_stack->stackA = game_stack->stackA->next;
		last_a_blob->next = temp_blob;
		temp_blob->next = NULL;
	}
	
	if(get_stack_length(game_stack->stackB) != 1){		
		Blob * temp_blob = game_stack->stackB;
		game_stack->stackB = game_stack->stackB->next;
		last_a_blob->next = temp_blob;
		temp_blob->next = NULL;
	}


	
	
	Blob * temp_blob = game_stack->stackA;
	game_stack->stackA = game_stack->stackA->next;
	temp_blob->next = game_stack->stackB;
	game_stack->stackB = temp_blob;
	
	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "rr\n");
	return 0;       
}

int simple_pb_one_chunk(Stack * game_stack, int chunk_start, int chunk_end)
{
	int size = get_stack_length(game_stack->stackA);
	int moved = 0;
	printf("\n szie %d\n", size);
	printf("\n chunk_end %d\n", chunk_end);
	int norm_at_top;
	int total_to_push = chunk_end - chunk_start;

	while(moved < total_to_push)
	{
		norm_at_top = get_norm_from_index(game_stack->stackA, 0);
		printf("\n norm_at_top %d\n", norm_at_top);
		if(norm_at_top > chunk_end){
			ra(game_stack);
		}else{
			pb(game_stack);
			if (norm_at_top < (chunk_start + chunk_end) / 2)
				rb(game_stack);
			moved++;
		}
		size = get_stack_length(game_stack->stackA);
	}
	return 0;
}

int  push_2_to_b(Stack * game_stack){
	int err = 0; 
	int i = 0;
	while (i < 2){		
		err = pb(game_stack);
		if(err)
			return 1;
		i++;
	}	
	return 0;
}



/**
we need need to test our lost cost effort
we need need to test our lost cost effort
we need need to test our lost cost effort
 */
void experiment_while_more_than_3(Stack * game_stack)
{

	fill_latest_cost(game_stack);
	Blob * candidate_from_A = game_stack->stackA;
	Blob * candidate_from_B = game_stack->stackB;

	get_lowest_cost(game_stack, candidate_from_A, candidate_from_B);



	


	candidate_from_A = NULL;
	candidate_from_B = NULL;
}

void simple_while_more_than_0(Stack * game_stack)
{
	int size = get_stack_length(game_stack->stackA);
	int chunk_count = 5;
	if (size < 10)
	{
		printf("\n ERROR: size too small\n");
		exit(EXIT_FAILURE);
	}
	if(size > 100)
		chunk_count = 10;
	
	int chunk_size = size / chunk_count;
	int chunk_start = 0;
	int chunk_end = chunk_size;
	while(chunk_start < size){
		simple_pb_one_chunk(game_stack, chunk_start, chunk_end);
		chunk_start = chunk_end;
		chunk_end = chunk_start + chunk_size;
	}
}

void simple_push_stupidly_back_a(Stack * game_stack){
	int current_norm;
	int position;
	current_norm = get_stack_length(game_stack->stackB) - 1;
	// int i = 0;
	while(current_norm > -1){

		   position = get_index_from_norm(game_stack->stackB, current_norm);

        if (position == -1)
        {
            printf("Error: normalized index %d not found in stack B\n",
                current_norm);
            return;
        }

        while (position != 0)
        {
            if (position < get_stack_length(game_stack->stackB) / 2)
                rb(game_stack);
            else
                rrb(game_stack);

            position = get_index_from_norm(
                game_stack->stackB, current_norm);

            if (position == -1)
            {
                return;
            }
        }

        pa(game_stack);
        current_norm--;


	


	}
}



void simple_push_all_chunks_to_b(Stack * game_stack){
	simple_while_more_than_0(game_stack);
	simple_push_stupidly_back_a(game_stack);	
}

void start_simple(Stack * game_stack){
	simple_push_all_chunks_to_b(game_stack);
}

int main (int argc, char **argv){



	Method method;
	method = ADAPTIVE;
	char * filtered_input = NULL;
	int err;

	Stack *game_stack;
	int * list_of_numbers;

	err = 0;
	if(argc == 1){
		printf("\n no arguments\n");
		return 0;
	}

	list_of_numbers = NULL;




	int number_input_start = 1;

	if(!process_valid_input(argc, argv, &number_input_start, &method))
	{
		return 1;
	}


	if (argc - number_input_start == 0)
	{		
		return 0;
	}
	list_of_numbers = (int * )malloc(sizeof(int) * (argc - number_input_start));


	if (!is_all_numbers(argv+number_input_start, &list_of_numbers, argc - number_input_start)){
		free(list_of_numbers);
		return 1;
	}	

	printf("\n he\n");
	
	game_stack = init_stack();
	game_stack->list_of_operations = NULL;
	fill_stack_values(game_stack, list_of_numbers, argc - number_input_start);

	fill_latest_cost(game_stack);

	fill_norm_index(game_stack);


		


	if(method == SIMPLE){
		printf("\n simple\n");
		// experiment_while_more_than_3(game_stack);
		// simple_while_more_than_3(game_stack);
		start_simple(game_stack);
	}else if(method == MEDIUM){		
		err = push_2_to_b(game_stack);
		if (err)
			return 1;
	}
	else
		return 1;
		
	


	display_stack_operations(game_stack->list_of_operations);

	#ifdef DEBUG
	display_state_output(game_stack);
	#endif


	
	free(filtered_input);
	free(list_of_numbers);

	list_of_numbers = NULL;

	free_game(game_stack);



	return 0;




}


