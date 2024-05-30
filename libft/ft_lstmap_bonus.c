/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:53:13 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/24 15:23:13 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*newptr;

	newptr = NULL;
	result = NULL;
	while (lst)
	{
		newptr = ft_lstnew(f(lst->content));
		if (!newptr)
		{
			ft_lstclear(&result, del);
			result = NULL;
			return (result);
		}
		ft_lstadd_back(&result, newptr);
		lst = lst->next;
	}
	return (result);
}
