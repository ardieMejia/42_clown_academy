#ifndef LIBINPUT_CLEANER_H

#define LIBINPUT_CLEANER_H



typedef struct Blob
{
	int value;
    int norm_index; // we should rename this to value_norm_index
	int cost;
	int index;
	// struct Blob * prev;
	struct Blob * next;
}Blob;


typedef struct Stack
{
    struct Blob *stackA;
    struct Blob *stackB;
    // int *list_of_numbers;
}Stack;


Stack * create_stack_and_fill_values(int *list_of_numbers, int list_of_numbers_length );

int get_index_from_norm(Blob* stack, int norm_index);

#endif // LIBINPUT_CLEANER_H
