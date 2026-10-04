/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 13:23:32 by arwan             #+#    #+#             */
/*   Updated: 2026/08/06 13:23:32 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	size_t	truelength;
	char	*new_substring;

	n = 0;
	truelength = ft_strlen(s) - start;
	if (len < truelength)
		truelength = len;
	if (start >= ft_strlen(s))
		truelength = 0;
	new_substring = malloc(sizeof(char) * truelength + 1);
	if (new_substring == NULL)
		return (NULL);
	while (n < truelength)
	{
		new_substring[n] = s[start + n];
		n++;
	}
	new_substring[n] = '\0';
	return (new_substring);
}
