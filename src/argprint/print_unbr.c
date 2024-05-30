/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:27:52 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/30 19:27:53 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sizecalc(unsigned int nbr)
{
	int	size;

	size = 0;
	while (nbr)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

static char	*ft_uitoa(unsigned int nbr)
{
	char	*result;
	int		size;

	size = sizecalc(nbr);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (nbr)
	{
		result[--size] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}

int	print_unbr(unsigned int nbr)
{
	char	*sunbr;
	int		bytesread;

	bytesread = 0;
	if (!nbr)
		return (write(1, "0", 1));
	sunbr = ft_uitoa(nbr);
	bytesread = print_str(sunbr);
	return (free(sunbr), bytesread);
}
