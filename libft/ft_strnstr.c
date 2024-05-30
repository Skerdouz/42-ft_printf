/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:29:30 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/22 11:30:15 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occsearch(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (big[i] && little[i] && i < len)
	{
		if (big[i] != little[i])
			return (0);
		i++;
	}
	if (!little[i])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
			if (occsearch(&big[i], little, len - i))
				return ((char *)big + i);
		i++;
	}
	return (NULL);
}
