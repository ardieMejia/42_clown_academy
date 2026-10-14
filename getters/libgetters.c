#include <stdlib.h>
#include <limits.h>
#include "../libstructutils/test.h"
#include "../libstructutils/libfillstruct.h"
#include "../libstructutils/libfilterinput.h"
#include "libgetters.h"




int get_stack_length(Blob * stack){
	int i = 0;
	while(stack){
		stack = stack->next;
		i++;
	}
	return i;
}

Blob * get_closest_candidate_from_A(Blob * stackA, int norm_index_from_b){
	Blob * closest_candidate = stackA;
	while(stackA){
		if(stackA->norm_index < closest_candidate->norm_index && stackA->norm_index > norm_index_from_b)
			closest_candidate = stackA;
		stackA = stackA->next;
	}
	return closest_candidate;
}

int get_lowest_cost(Stack * game_stack, Blob* candidate_from_A, Blob* candidate_from_B)
{
	// game_stack->stackA->value = 4;
	// amount_to_calculate = 4;
	// printf("\n amount to cauflate %d\n", amount_to_calculate);
	// return 99;
	fill_latest_cost(game_stack);
	int i = 0;
	int combined_cost = 0;
	int lowest_total_cost = INT_MAX;
	int offset_to_search = get_stack_length(game_stack->stackB)/2;
	Blob * current_tracker = game_stack->stackB;
	int norm_index_lowest_cost_from_B = current_tracker->norm_index;
	while(i < offset_to_search && !current_tracker){
		candidate_from_A = get_closest_candidate_from_A(game_stack->stackA, current_tracker->norm_index);
		combined_cost = candidate_from_A->cost + current_tracker->cost;
		if (combined_cost < lowest_total_cost)
			candidate_from_B = current_tracker;
		current_tracker = current_tracker->next;
		i++;
	}
}
