#include "../libft/libft.h"
#include "test.h"
#include "libfillstruct.h"
#include "libfilterinput.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../getters/libgetters.h"
#include "libfree.h"








// char * _filter_arguments(int argc, char** argv){
	
// 	char * filtered_input = ft_strdup("5 4 3 2 1 10 9 6 7 8");
// 	return filtered_input;
// }


// char * filter_arguments(char * filtered_input, int * method, char ** argc, int argv);
// char * filter_arguments(char ** filtered_input, int * method, char ** argc, int argv){


int is_method(char * maybe_option, Method * method){
	int result = 1;

	if (ft_strncmp(maybe_option, "--simple", 8))
		*method = SIMPLE;
	else if (ft_strncmp(maybe_option, "--medium", 8))
		*method = MEDIUM;
	else if (ft_strncmp(maybe_option, "--complex", 9))
		*method = COMPLEX;
	else if (ft_strncmp(maybe_option, "--adaptive", 10))
		*method = ADAPTIVE;
	else
		result = 0;
	return result;
}

int is_argument_numbers(char ** the_rest, int argc)
{
	int length = argc - 2;
	int i = 0;
	int * array_of_numbers = malloc(sizeof(int) * length );
	while(i < length - 1){
		array_of_numbers[i] = ft_atoi(*the_rest);
		the_rest++;
		i++;
	}
	return 0;
}



// int get_length_filtered_input(char ** filtered_input)
// {
// 	char ** numbers_with_spaces = ft_split(filtered_input, ' ');
// 	int i = 0;
// 	while(numbers_with_spaces[i]){
// 		i++;
// 	}


// 	// printf("\n length %d\n", i);
// 	// free(numbers_with_spaces);
// 	free_split_string(numbers_with_spaces);
// 	return i;

// }


int is_all_numbers(char ** filtered_input_split, int ** list_of_numbers, int length){
	int i = 0;
	char * current_string;

	while(i < length){
		current_string = filtered_input_split[i];
		while(*current_string){
			if(!ft_isdigit(*current_string)){
				return 0;
			}
			current_string++;
		}
		(*list_of_numbers)[i] = ft_atoi(filtered_input_split[i]);

		i++;
	}






	return 1;
}


int is_valid_input(int *argc, char ** arguments, int ** list_of_numbers, Method *method)
{
	char * maybe_option = arguments[1];
	char * found = NULL;





	// *filtered_input = ft_strdup("5 4 3 2 1 10 9 6 7 8");


	if (is_method(maybe_option, method)){
		arguments++;
		(*argc)--;
	}



	*list_of_numbers = (int * )malloc(sizeof(int) * *argc);



	maybe_option = NULL;



	if (!is_all_numbers(arguments, list_of_numbers, *argc))
		return 0;
		

	return 1;

	
	

	
	// return found;


}



// int filter_arguments_and_return_error(char ** filtered_input, Method * method, int argc, char ** argv){
// 	char * option;
// 	char * error_message;


// 	error_message = ft_strdup("Error");

// 	if (!option_valid_return_method_and_rest(argc, argv, &the_rest, method)){
// 		write(0,error_message, ft_strlen(error_message));
// 		return 1;
// 	}

// 	filtered_input = get_the_numbers(argv);
	
// 	// method = get_option();
	
// 	// *filtered_input = ft_strdup("5 4 3 2 1 10 9 6 7 8");

// 	return 0;
// }

int is_valid_option_string(char * flag, Method * method){
	int result = 1;


	if (!ft_strncmp(flag, "--simple", 9))
		*method = SIMPLE;
	else if (!ft_strncmp(flag, "--medium", 9))
		*method = MEDIUM;
	else if (!ft_strncmp(flag, "--complex", 10))
		*method = COMPLEX;
	else if (!ft_strncmp(flag, "--adaptive", 11))
		*method = ADAPTIVE;
	else if (!ft_strncmp(flag, "--bench", 8))
		*method = BENCH;
	else
		result = 0;
	return result;
}

int is_first_arg_number(int argc, char ** argv)
{
	if(ft_atoi(argv[1]) == 0 && !ft_isdigit(argv[1][0]))
		return 0;
	return 1;
}

int is_second_arg_number(int argc, char ** argv)
{
	if(ft_atoi(argv[2]) == 0 && !ft_isdigit(argv[2][0]))
		return 0;
	return 1;
}

int process_first_arg_if_valid(int argc, char ** argv, Method * method)
{
	if(!is_valid_option_string(argv[1], method))
	{
		return 0;
	}
	return 1;
}

int process_second_arg_if_valid(int argc, char ** argv, Method * method)
{       	
	if(!is_valid_option_string(argv[2], method))
	{
		return 1;
	}
	return 0;
}

int process_valid_input(int argc, char ** argv, Method * method)
{
	int i = 1;
	Method temp_method = ADAPTIVE;
	if (argc == 1){
		// write(1,"Error\n",6);
		return 0;
	}
	int number_input_start = 1;
	if (argc > 1){
		if (!is_first_arg_number(argc, argv))
		{
			if(!process_first_arg_if_valid(argc, argv, method))
				return 0;
			else
				number_input_start++;
		}
		if (*method == BENCH){
			printf("\n bench turned on\n");			
		}
		else
			temp_method = *method;
		if (argc > 2 && !is_second_arg_number(argc, argv))
		{
			if(!process_second_arg_if_valid(argc, argv, method))
				return 0;
			else
				number_input_start++;
		}
		if (*method == BENCH)
			printf("\n bench turned on\n");
		else
			temp_method = *method;

		*method = temp_method;
		
		// get_method();
		// get_number_list();
	}
	i = number_input_start;
		while(i<argc){
			printf("\n current num %d\n", ft_atoi(argv[i]));
			i++;
		}
		printf("\n method: %d\n", *method);
	return 0;
}
