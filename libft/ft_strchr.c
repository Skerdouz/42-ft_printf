/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:18:01 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/22 14:00:27 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	chr;

	chr = c;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
