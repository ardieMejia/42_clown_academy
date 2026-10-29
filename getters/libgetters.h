#ifndef LIBGETTER_H

#define LIBGETTER_H


Blob * get_closest_candidate_from_A(Blob * stack_A, int norm_index_from_b);
int get_lowest_cost(Stack * game_stack, Blob* candidate_from_A, Blob* candidate_from_B);
int get_stack_length(Blob * stack);
Blob * get_last_blob(Blob * stack);
Blob * get_next_to_last_blob(Blob * stack);

int get_index_from_norm(Blob* stack, int norm_index);
int get_norm_from_index(Blob* stack, int position);
int get_value_from_index(Blob* blob, int position);

int get_less_than_sqrt(int number);
    
#endif // LIBGETTER_H
