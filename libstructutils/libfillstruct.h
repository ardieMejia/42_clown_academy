#ifndef LIBFILLSTRUCT_H

#define LIBFILLSTRUCT_H

#include <stdbool.h>


typedef enum  Method{
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE,
    BENCH
} Method;



enum Half {
    TOP_HALF,
    BOTTOM_HALF
};

typedef struct Blob
{
    int value;
    int norm;
    int cost;
    enum Half half;
    struct Blob * next;
    struct Blob * prev;
    bool bench;
}Blob;


typedef struct Stack
{
    struct Blob *stackA;
    struct Blob *stackB;
    char * list_of_operations;
}Stack;

Stack * init_stack();
    

void fill_stack_values(Stack* game_stack, int * list_of_numbers, int list_of_numbers_length );
void fill_latest_cost(Stack * game_stack);





#endif // LIBFILLSTRUCT_H
