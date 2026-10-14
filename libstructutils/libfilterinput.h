#ifndef LIBFILTERINPUT_H

#define LIBFILTERINPUT_H



// char ** get_method(char * maybe_option, Method * method);
int is_method(char * maybe_option, Method * method);

// char ** get_option(char * maybe_option){


// int get_argument_numbers(char ** the_rest);
int is_argument_numbers(char ** the_rest, int argc);

// int get_length_filtered_input(char ** filtered_input);



int is_all_numbers(char ** filtered_input_split, int ** list_of_numbers, int length);

    


int is_valid_input(int *argc, char ** argv, int ** list_of_numbers, Method *method);
   








#endif // LIBFILTERINPUT_H
