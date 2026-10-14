#include "../libft/libft.h"
#include "test.h"
#include "libfillstruct.h"
#include "libfilterinput.h"
#include <stdlib.h>
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



int is_valid_input(int *argc, char ** argv, int ** list_of_numbers, Method *method)
{
	char * maybe_option = argv[1];
	char * found = NULL;




	// *filtered_input = ft_strdup("5 4 3 2 1 10 9 6 7 8");


	if (is_method(maybe_option, method)){
		argv++;
		(*argc)--;
	}



	*list_of_numbers = (int * )malloc(sizeof(int) * *argc);




	

	

	if (!is_all_numbers(argv, list_of_numbers, *argc))
		return 0;
		
	// free_split_string(argv);
	// free(maybe_option);
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


