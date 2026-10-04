/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:23:13 by arwan             #+#    #+#             */
/*   Updated: 2026/08/04 16:23:13 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*some;
	int		len;

	len = ft_strlen(s);
	i = 0;
	some = malloc(len + 1);
	if (!some)
		return (NULL);
	while (i < len)
	{
		*(some + i) = *(char *)s;
		s++;
		i++;
	}
	*(some + i) = '\0';
	return (some);
}
