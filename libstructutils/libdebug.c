#include <stdlib.h>
#include <stdio.h>
#include "test.h"
#include "libfillstruct.h"
#include "libfilterinput.h"
#include "libfree.h"
#include "libdebug.h"
#include "../libft/libft.h"
#include "../getters/libgetters.h"


// int get_at_i_aschar(Blob * blob, char * string, int n)
// {
// 	int i;
// 	i = 0;
// 	string = ft_strdup(" ");
// 	while(i < n)
// 	{
// 		i++;
// 		blob = blob->next;
// 	}
// }

void display_state_output(Stack * game_stack)
{
	printf("\n printing debug info...\n");
	int size_a = 0;
	int size_b = 0;
	char * value_a;
	char * value_b;
	int i = 0;
	printf("=====\n");
	size_a = get_stack_length(game_stack->stackA);
	size_b = get_stack_length(game_stack->stackB);
	int biggest = size_a;
	if (size_b > size_a)  biggest = size_b;
	while(i < biggest)
	{
		// get_at_i_aschar(game_stack->stackA, value_a, i);
		// get_at_i_aschar(game_stack->stackB, value_b, i);
		if (i < size_a)
			value_a = ft_itoa(get_value_from_index(game_stack->stackA, i));
		else
			value_a = ft_strdup(" ");
		if (i < size_b)
			value_b = ft_itoa(get_value_from_index(game_stack->stackB, i));
		else
			value_b = ft_strdup(" ");

		printf("%s | %s\n", value_a, value_b);
		i++;
	}
}

	
