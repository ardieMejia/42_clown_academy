/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:56:54 by arwan             #+#    #+#             */
/*   Updated: 2026/08/03 13:56:54 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			n;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	n = 0;
	if (len == 0)
		return (0);
	len = len - 1;
	while (*(str1 + n) == *(str2 + n))
	{
		if (n == len)
			break ;
		n++;
	}
	if (*(str1 + n) != *(str2 + n))
		return (*(str1 + n) - *(str2 + n));
	return (0);
}
