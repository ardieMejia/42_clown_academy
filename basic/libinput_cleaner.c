
#include <stdlib.h>
#include "libinput_cleaner.h"


Stack * prepare_stack_values(int *list_of_numbers, int list_of_numbers_length )
{
	Stack *game_stack = (Stack *)malloc(sizeof(Stack));
	int i = 0;
	Blob *current_pointer = NULL;
	Blob *tracking_pointer = NULL;
	game_stack->stackA=NULL;

	while(i < list_of_numbers_length){
		current_pointer = malloc(sizeof(Blob));		
		current_pointer->value = list_of_numbers[i];
		current_pointer->norm_index = list_of_numbers[i];
		current_pointer->next = NULL;

		if(game_stack->stackA == NULL)
		{
			game_stack->stackA = current_pointer;
			tracking_pointer=current_pointer;
		}else{
			tracking_pointer->next=current_pointer;
			tracking_pointer=tracking_pointer->next;
			
		}
		// free(current_blob_pointer);
		i++;
	}

	// free(current_pointer);
	// free(tracking_pointer);

	return game_stack;



}
