/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:09:41 by arwan             #+#    #+#             */
/*   Updated: 2026/08/04 13:09:41 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	inner_while(char **little, char **pattern_tracker, size_t *n_tr)
{
	while (*(*little + *n_tr) != '\0' && **pattern_tracker != '\0')
	{
		if (*(*little + *n_tr) != **pattern_tracker)
		{
			return ;
		}
		*pattern_tracker = *pattern_tracker + 1;
		*n_tr = *n_tr + 1;
	}
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n_tr;
	size_t	n;
	char	*pattern_tracker;

	n_tr = 0;
	n = 0;
	pattern_tracker = (char *)big;
	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && n < len)
	{
		inner_while((char **)(&little), &pattern_tracker, &n_tr);
		if (*(little + n_tr) == '\0' && n_tr + n <= len)
		{
			return ((char *)big);
		}
		big++;
		n++;
		n_tr = 0;
		pattern_tracker = (char *)big;
	}
	return (NULL);
}
