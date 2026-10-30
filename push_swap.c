
 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>



#include "libstructutils/libfillstruct.h"
#include "libstructutils/libfilterinput.h"
#include "libstructutils/libdebug.h"
#include "getters/libgetters.h"
#include "libft/libft.h"
#include "libstructutils/libfree.h"


#include "simple.h"
#include "medium.h"




void base_swap(int * a, int * b){
	int temp = * a;
	* a = *b;
	*b = temp;
}






void display_stack_operations(char * list_of_operations){


	// char * test = strdup("hallsd\nlsd");
	// char * test = ft_strdup("hallsd\nlsd");

	

	// list_of_operations[2] = 's';

	// write(int __fd, const void *__buf, size_t __n);
	write(0,list_of_operations , ft_strlen(list_of_operations));
		
}














void fill_norm(Stack * game_stack)
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
				current->norm = i ;
			current = current->next;
		}
		i++;
	}

	// printf("\n game_stack first norm (4 i think): %d\n", game_stack->stackA->norm_index);
	free(temp_array);
}











Stack * create_game_stack(int * list_of_numbers, int length)

{
	Stack *game_stack;
		
	game_stack = init_stack();
	game_stack->list_of_operations = NULL;
	fill_stack_values(game_stack, list_of_numbers, length);

	fill_latest_cost(game_stack);
	fill_norm(game_stack);
	return game_stack;
	
}



int main (int argc, char **argv){

	Method method;
	method = ADAPTIVE;
	char * filtered_input = NULL;

	int * list_of_numbers;

	if(argc == 1){
		printf("\n no arguments\n");
		return 0;
	}

	list_of_numbers = NULL;

	int number_input_start = 1;

	if(!process_valid_input(argc, argv, &number_input_start, &method))
	{
		write(1,"Error\n",6);
		return 1;
	}


	if (argc - number_input_start == 0)
		return 0;

	list_of_numbers = (int * )malloc(sizeof(int) * (argc - number_input_start));


	if (!is_all_numbers(argv+number_input_start, &list_of_numbers, argc - number_input_start)){
		free(list_of_numbers);
		return 1;

	}
	Stack * game_stack = create_game_stack(list_of_numbers, argc - number_input_start);

	

	if(method == SIMPLE){
		printf("\n simple\n");
		start_simple(game_stack);
	}else if(method == MEDIUM){
		start_medium(game_stack);
	}
	else if(method == COMPLEX)
		printf("\n medium\n");
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


