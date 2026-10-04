/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:02:03 by arwan             #+#    #+#             */
/*   Updated: 2026/07/31 16:02:03 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	char	*temp_src;

	temp_src = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(temp_src));
	n = 0;
	while (n < dstsize - 1)
	{
		if (*src == '\0')
		{
			*dst = '\0';
			return (ft_strlen(temp_src));
		}
		*dst = *(char *)src;
		dst++;
		src++;
		n++;
	}
	*dst = '\0';
	return (ft_strlen(temp_src));
}
