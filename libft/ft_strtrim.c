/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:08:48 by arwan             #+#    #+#             */
/*   Updated: 2026/08/06 16:08:48 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char current, char *set)
{
	int	found;

	found = 0;
	while (*set != '\0')
	{
		if (current == *set)
		{
			found = 1;
			break ;
		}
		set++;
	}
	return (found);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		n_start;
	int		n_end;
	char	*new_string;

	n_start = 0;
	n_end = ft_strlen(s1) - 1;
	while (*(s1 + n_start) != '\0' && is_set(*(s1 + n_start), (char *)set))
		n_start++;
	while (n_end > n_start && is_set(*(s1 + n_end), (char *)set))
		n_end--;
	new_string = (char *)malloc(n_end - n_start + 2);
	ft_memmove(new_string, s1 + n_start, n_end - n_start + 1);
	new_string[n_end - n_start + 1] = '\0';
	return (new_string);
}
