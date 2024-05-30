/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:50:53 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/24 13:10:45 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*nextptr;

	if (!*lst)
		return ;
	ptr = *lst;
	while (ptr->next)
	{
		nextptr = ptr->next;
		(*del)(ptr->content);
		free(ptr);
		ptr = nextptr;
	}
	(*del)(ptr->content);
	free(ptr);
	*lst = NULL;
}
