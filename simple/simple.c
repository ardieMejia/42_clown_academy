#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../libstructutils/libfillstruct.h"
#include "../libstructutils/libfilterinput.h"
#include "../libstructutils/libdebug.h"
#include "../getters/libgetters.h"
#include "../libft/libft.h"
#include "../libstructutils/libfree.h"
#include "../liboperations/liboperations.h"

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
