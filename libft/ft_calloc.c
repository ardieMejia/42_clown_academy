/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:50:49 by arwan             #+#    #+#             */
/*   Updated: 2026/08/04 15:50:49 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mymem;
	size_t	total_bytes;
	size_t	i;

	i = 0;
	if (nmemb != 0 && size != 0)
	{
		total_bytes = nmemb * size;
		if (total_bytes / nmemb != size)
			return (NULL);
	}
	else
		total_bytes = 0;
	mymem = malloc(total_bytes);
	if (!mymem)
		return (NULL);
	while (i < total_bytes)
	{
		((char *)mymem)[i] = 0;
		i++;
	}
	return (mymem);
}
