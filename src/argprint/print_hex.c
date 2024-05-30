/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:28:06 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/30 19:28:07 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sizecalc(size_t nbr)
{
	int	size;

	size = 0;
	while (nbr)
	{
		size++;
		nbr /= 16;
	}
	return (size);
}

static char	*ft_uitoa_hex(size_t nbr, const char format)
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
		if (nbr % 16 < 10)
			result[--size] = (nbr % 16) + '0';
		else
		{
			if (format == 'x')
				result[--size] = ((nbr % 16) - 10) + 'a';
			else
				result[--size] = ((nbr % 16) - 10) + 'A';
		}
		nbr /= 16;
	}
	return (result);
}

int	print_hex(size_t nbr, const char format)
{
	int		bytesread;
	char	*result;

	bytesread = 0;
	if (!nbr)
		return (write(1, "0", 1));
	result = ft_uitoa_hex(nbr, format);
	if (!result)
		return (0);
	bytesread = print_str(result);
	return (free(result), bytesread);
}
