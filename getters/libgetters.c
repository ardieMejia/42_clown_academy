#include <stdlib.h>
#include <limits.h>
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


Blob * get_last_blob(Blob * stack){

	Blob * temp_blob = stack;
	while(temp_blob->next){
		temp_blob=temp_blob->next;
	}
	return temp_blob;
}


Blob * get_next_to_last_blob(Blob * stack){
	Blob * temp_blob = stack;
	while(temp_blob->next->next){
		temp_blob=temp_blob->next;
	}
	return temp_blob;	
}

int get_less_than_sqrt(int number){
	int answer = 1;	
	while(answer <= number){
		if (answer*answer > number )
			break;

			
		answer++;
	}
	return answer - 1;
}


int get_value_from_index(Blob* blob, int position){
	int i = 0;
	int norm_index = 99;
	while (blob)
	{
		if(i == position)
			return blob->value;
		i++;
		blob=blob->next;		
	}
	return -99;
}

int get_norm_from_index(Blob* blob, int position){
	int i = 0;
	int norm_index = 99;
	while (blob)
	{
		if(i == position)
			return blob->norm_index;
		i++;
		blob=blob->next;		
	}
	return -99;
}

int get_index_from_norm(Blob* head, int norm_index)
{
	if (!head)
		abort();
	int i = 0;
	Blob *current_pointer = head;



	while(current_pointer){
		if (current_pointer->norm_index == norm_index)
			return i;
		current_pointer = current_pointer->next;
		i++;
	}

	current_pointer = NULL;

	return -1;

}
