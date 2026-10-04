/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:42:21 by arwan             #+#    #+#             */
/*   Updated: 2026/08/11 17:42:21 by arwan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_lst;
	t_list	*current;

	if (!*lst)
		return ;
	current = *lst;
	while (current)
	{
		temp_lst = current->next;
		ft_lstdelone(current, del);
		current = temp_lst;
	}
	*lst = NULL;
}
