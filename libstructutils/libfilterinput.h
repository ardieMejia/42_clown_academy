#ifndef LIBFILTERINPUT_H

#define LIBFILTERINPUT_H









int is_method(char * maybe_option, Method * method);
int is_argument_numbers(char ** the_rest, int argc);
// int is_all_numbers(char ** filtered_input_split, int ** list_of_numbers, int length);
// int is_all_numbers(char ** filtered_input_split, int ** list_of_numbers, int length);
int is_all_numbers(char ** snipped_argv, int ** list_of_numbers, int length);
int is_valid_input(int *argc, char ** arguments, int ** list_of_numbers, Method *method);
int is_valid_option_string(char * flag, Method * method);
int is_second_arg_number(int argc, char ** argv);
		

int process_first_arg_if_valid(int argc, char ** argv, Method * method);
int process_second_arg_if_valid(int argc, char ** argv, Method * method);
int process_valid_input(int argc, char ** argv, int * number_input_start, Method * method);






#endif // LIBFILTERINPUT_H
