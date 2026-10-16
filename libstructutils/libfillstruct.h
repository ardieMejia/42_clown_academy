#ifndef LIBFILLSTRUCT_H

#define LIBFILLSTRUCT_H


typedef enum  Method{
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE
} Method;

enum Half {
    TOP_HALF,
    BOTTOM_HALF
};

typedef struct Blob
{
    int value;
    int norm_index; // we should rename this to value_norm_index
    int cost;
    enum Half half;
    // struct Blob * prev;
    struct Blob * next;
}Blob;


typedef struct Stack
{
    struct Blob *stackA;
    struct Blob *stackB;
    char * list_of_operations;
}Stack;


typedef struct Chunk
{
	int		lower;
	int		upper;
}	Chunk;



Stack * init_stack();
    

void fill_stack_values(Stack* game_stack, int * list_of_numbers, int list_of_numbers_length );
void fill_latest_cost(Stack * game_stack);



int get_index_from_norm(Blob* stack, int norm_index);
int get_norm_from_index(Blob* stack, int position);
int get_value_from_index(Blob* blob, int position);

#endif // LIBFILLSTRUCT_H
