
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../libstructutils/libfillstruct.h"
#include "../libstructutils/libfilterinput.h"
#include "../libstructutils/libfree.h"
#include "../getters/libgetters.h"


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

	
	// game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "ra\n");
	old_head = NULL;
	new_head = NULL;
	last_blob = NULL;
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

	// char *temp_list_of_operations = ft_strjoin(game_stack->list_of_operations, "rrb\n");
	// free(game_stack->list_of_operations);
	// game_stack->list_of_operations = temp_list_of_operations;

	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "rrb\n");
	
	temp_last_blob = NULL;
	temp_next_to_last_blob = NULL;
	return 0;
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

	char *temp_list_of_operations = ft_strjoin(game_stack->list_of_operations, "rra\n");
	free(game_stack->list_of_operations);
	game_stack->list_of_operations = temp_list_of_operations;
	
	temp_last_blob = NULL;
	temp_next_to_last_blob = NULL;
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

	// game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "rb\n");
	old_head = NULL;
	new_head = NULL;
	last_blob = NULL;
	return 0;

}
