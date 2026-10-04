/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:44:23 by arwan             #+#    #+#             */
/*   Updated: 2026/08/06 14:44:23 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	int		n;
	int		offset;

	new_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_string == NULL)
	{
		free(new_string);
		return (NULL);
	}
	offset = ft_strlen(s1);
	n = 0;
	while (*(s1 + n) != '\0')
	{
		*(new_string + n) = *(s1 + n);
		n++;
	}
	n = 0;
	while (*(s2 + n) != '\0')
	{
		*(new_string + offset + n) = *(s2 + n);
		n++;
	}
	*(new_string + offset + n) = '\0';
	return (new_string);
}
