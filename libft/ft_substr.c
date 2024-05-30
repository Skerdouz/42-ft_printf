/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:15:16 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/24 11:28:15 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	alloc;
	char	*result;

	i = 0;
	if (start > ft_strlen(s))
	{
		result = malloc(1 * sizeof(char));
		if (!result)
			return (NULL);
	}
	else
	{
		alloc = (ft_strlen(s) - start) + 1;
		if ((start + len) > ft_strlen(s))
			result = malloc (alloc * sizeof(char));
		else
			result = malloc((len + 1) * sizeof(char));
		if (!result)
			return (NULL);
		while (i < len && start < ft_strlen(s))
			result[i++] = s[start++];
	}
	result[i] = '\0';
	return (result);
}
