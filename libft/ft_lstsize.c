/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:12:30 by arwan             #+#    #+#             */
/*   Updated: 2026/08/11 16:12:30 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	t_list			*temp_lst;
	unsigned int	count;

	temp_lst = lst;
	count = 0;
	while (temp_lst)
	{
		temp_lst = temp_lst->next;
		count++;
	}
	return (count);
}
