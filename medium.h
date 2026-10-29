#ifndef MEDIUM_H

#define MEDIUM_H


// int  push_2_to_b(Stack * game_stack);

void start_medium(Stack * game_stack);
// void push_current_upper_chunk_to_b(game_stack);
void push_current_upper_chunk_to_b(Stack * game_stack, int lower, int upper);
// void sort_bucket(Stack * game_stack, int lower, int upper);
void push_back_to_descending(Stack * game_stack, int lower, int upper);
    
#endif // MEDIUM_H

