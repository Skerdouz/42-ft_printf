/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:28:03 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/30 19:28:04 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int nbr)
{
	char	*snbr;
	int		bytesread;

	bytesread = 0;
	snbr = ft_itoa(nbr);
	bytesread = print_str(snbr);
	return (free(snbr), bytesread);
}
