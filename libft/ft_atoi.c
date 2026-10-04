/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:09:52 by arwan             #+#    #+#             */
/*   Updated: 2026/08/04 14:09:52 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign_and_move(char **nptr)
{
	int	sign;

	sign = 1;
	while ((**nptr >= 9 && **nptr <= 13) || **nptr == ' ')
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int		num;
	int		sign;
	char	*temp_nptr;

	num = 0;
	sign = 1;
	temp_nptr = (char *)nptr;
	sign = get_sign_and_move(&temp_nptr);
	if (sign == 0)
		return (0);
	while (*temp_nptr >= '0' && *temp_nptr <= '9')
	{
		num = num * 10 + (*temp_nptr - '0');
		temp_nptr++;
	}
	return (num * sign);
}
