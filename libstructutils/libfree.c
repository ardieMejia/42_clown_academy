#include "../libft/libft.h"
#include "libfillstruct.h"
#include "libfilterinput.h"
#include "libfree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../getters/libgetters.h"

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

void free_game(Stack *game_stack){
	Blob * tracker = game_stack->stackA;
	Blob * current = game_stack->stackA;
	
	while(tracker){
		tracker=current->next;
		free(current);
		current=tracker;
	}
	
	tracker = game_stack->stackB;
	current = game_stack->stackB;
	
	while(tracker){
		tracker=current->next;
		free(current);
		current=tracker;
	}

	free(game_stack->list_of_operations);

	free(game_stack);
	game_stack=NULL;
	
}
