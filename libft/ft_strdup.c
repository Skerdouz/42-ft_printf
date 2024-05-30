/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:13:54 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/16 11:13:54 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		length;
	int		i;

	length = ft_strlen(s);
	result = malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
