/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:37:07 by arwan             #+#    #+#             */
/*   Updated: 2026/08/09 20:37:07 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		n;
	char	*new_string;

	n = 0;
	if (s == NULL)
		return (NULL);
	new_string = (char *)malloc(ft_strlen(s) + 1);
	if (!new_string)
		return (NULL);
	while (*(s + n) != '\0')
	{
		*(new_string + n) = f(n, *(s + n));
		n++;
	}
	new_string[n] = '\0';
	return (new_string);
}
