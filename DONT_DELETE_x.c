/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:40:14 by arwan             #+#    #+#             */
/*   Updated: 2026/08/11 16:40:14 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */







#include "libstructutils/libfillstruct.h"
#include "libstructutils/libfilterinput.h"
#include "libstructutils/libdebug.h"
#include "getters/libgetters.h"
#include "libft/libft.h"
#include "libstructutils/libfree.h"
#include "liboperations/liboperations.h"
#include "complex.h"

void	flush(Stack * game_stack)
{
	while (game_stack->stackB)
		pa(game_stack);
}

int	get_bit_count(int max_norm)
{
	int	bits;

	bits = 0;
	while (max_norm)
	{
		bits++;
		max_norm >>= 1;
	}
	return (bits);
}


void	complex_sort(Stack * game_stack)
{

	int		max_bits;
	int		i;
	int		count;


	max_bits = get_bit_count(get_stack_length(game_stack->stackA) - 1);
	i = 0;
	while (i < max_bits)
	{
		count = get_stack_length(game_stack->stackA);
		while (count--)
		{
			if ((get_norm_from_position(game_stack->stackA, 0) >> i) & 1)
				ra(game_stack);
			else
				pb(game_stack);
		}
		flush(game_stack);
		i++;
	}
}

