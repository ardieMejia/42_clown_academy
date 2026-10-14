
#include <stdlib.h>
#include "test.h"
#include "libfillstruct.h"
#include "libfilterinput.h"
#include "libfree.h"
#include "../getters/libgetters.h"




Stack * init_stack(){
	Stack *game_stack = (Stack *)malloc(sizeof(Stack));
	return game_stack;
}
	
void fill_stack_values(Stack* game_stack, int * list_of_numbers, int list_of_numbers_length )
{
	int i = 0;
	Blob *current_pointer = NULL;
	Blob *tracking_pointer = NULL;
	game_stack->stackA=NULL;
	game_stack->stackB=NULL;

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
	




}

void fill_latest_cost(Stack * game_stack)
{
	Blob * current_tracker = game_stack->stackA;
	while(current_tracker)
	{
		if (get_index_from_norm(game_stack->stackA, current_tracker->norm_index) < get_stack_length(game_stack->stackA)/2)
			current_tracker->cost = get_index_from_norm(game_stack->stackA, current_tracker->norm_index);
		else
			current_tracker->cost = get_stack_length(game_stack->stackA) - get_index_from_norm(game_stack->stackA, current_tracker->norm_index);
		current_tracker = current_tracker->next;
	}
	current_tracker=NULL;
}




int get_index_from_norm(Blob* head, int norm_index)
{
	if (!head)
		abort();
	int i = 0;
	Blob *current_pointer = head;



	while(current_pointer){
		if (current_pointer->norm_index == norm_index)
			break;
		current_pointer = current_pointer->next;
		i++;
	}

	current_pointer = NULL;

	return i;

}
