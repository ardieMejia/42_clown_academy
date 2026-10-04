/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:15:45 by arwan             #+#    #+#             */
/*   Updated: 2026/08/03 11:15:45 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		n;

	ptr = (char *)s;
	n = 0;
	if (c > 255)
		return (ptr);
	while (*ptr != '\0')
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
		n++;
	}
	if (c != '\0')
		return (NULL);
	return (ptr);
}
