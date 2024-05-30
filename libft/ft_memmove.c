/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:37:14 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/24 10:41:17 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*pdest;
	char	*psrc;

	i = 0;
	pdest = (char *)dest;
	psrc = (char *)src;
	if (!pdest && !psrc)
		return (NULL);
	if (pdest > psrc)
		while (n-- > 0)
			pdest[n] = psrc[n];
	else
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (dest);
}
