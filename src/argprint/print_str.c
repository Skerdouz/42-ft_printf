/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:27:55 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/30 19:27:56 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	bytesread;

	bytesread = 0;
	if (!str)
		return (print_str("(null)"));
	while (*str)
		bytesread += print_char((int)*(str++));
	return (bytesread);
}
