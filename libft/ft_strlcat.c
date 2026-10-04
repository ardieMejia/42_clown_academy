/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 08:34:50 by arwan             #+#    #+#             */
/*   Updated: 2026/08/02 08:34:50 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_max;
	size_t	dst_max;
	size_t	n;
	size_t	i;
	size_t	copy_len;

	src_max = ft_strlen(src);
	dst_max = ft_strlen(dst);
	n = dst_max;
	i = 0;
	copy_len = size - dst_max - 1;
	if (size <= dst_max)
		return (size + src_max);
	while (*(src + i) != '\0' && i < copy_len)
	{
		*(dst + n) = *(src + i);
		n++;
		i++;
	}
	*(dst + n) = '\0';
	if (size > dst_max)
		return (dst_max + src_max);
	return (1);
}
