/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:17:34 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/29 10:04:03 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memalloc;

	if (size && ((nmemb * size) / size != nmemb))
		return (NULL);
	memalloc = malloc(nmemb * size);
	if (!memalloc)
		return (NULL);
	memalloc = ft_memset(memalloc, 0, nmemb * size);
	return (memalloc);
}
