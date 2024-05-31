/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:02:42 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/31 09:54:10 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printer(const char format, va_list aptr)
{
	int	bytesread;

	bytesread = 0;
	if (format == 'c')
		bytesread = print_char(va_arg(aptr, int));
	else if (format == 's')
		bytesread = print_str(va_arg(aptr, char *));
	else if (format == 'd' || format == 'i')
		bytesread = print_nbr(va_arg(aptr, int));
	else if (format == 'u')
		bytesread = print_unbr(va_arg(aptr, unsigned int));
	else if (format == 'p')
		bytesread = print_ptr(va_arg(aptr, void *));
	else if (format == 'x' || format == 'X')
		bytesread = print_hex(va_arg(aptr, unsigned int), format);
	else if (format == '%')
		bytesread = print_percent();
	return (bytesread);
}

int	ft_printf(const char *format, ...)
{
	int		bytesread;
	va_list	aptr;

	if (!format)
		return (0);
	va_start(aptr, format);
	bytesread = 0;
	while (*format)
	{
		if (*format == '%')
			bytesread += printer(*++format, aptr);
		else
			bytesread += print_char(*format);
		format++;
	}
	return (va_end(aptr), bytesread);
}
