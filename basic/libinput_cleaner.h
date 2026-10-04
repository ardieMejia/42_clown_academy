#ifndef LIBINPUT_CLEANER_H

#define LIBINPUT_CLEANER_H



typedef struct Blob
{
	int value;
	int norm_index;
	// struct Blob * prev;
	struct Blob * next;
}Blob;


typedef struct Stack
{
	struct Blob *stackA;
	struct Blob *stackB;
}Stack;


Stack * prepare_stack_values(int *list_of_numbers, int list_of_numbers_length );

#endif // LIBINPUT_CLEANER_H
