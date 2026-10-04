/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:25:47 by arwan             #+#    #+#             */
/*   Updated: 2026/07/30 16:25:47 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	n;
	void	*original;

	n = 0;
	original = dest;
	while (n < len)
	{
		*(char *)dest = c;
		n++;
		dest++;
	}
	return (original);
}
