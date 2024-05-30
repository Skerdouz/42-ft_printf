/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:52:28 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/22 14:00:43 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;

	chr = c;
	i = ft_strlen(s);
	while (i != -1)
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
