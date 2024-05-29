/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:02:42 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/29 15:45:36 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	printer(char c, va_list aptr)
{
	int	bytesread;

	bytesread = 0;
	if (c == 'c')
		bytesread = print_char(va_arg(aptr, int));
	else if (c == 's')
		bytesread = print_string(va_arg(aptr, char *));
	// else if (c == 'p')
	// 	bytesread = print_pointer(va_arg(aptr, char));
	// else if (c == 'd')
	// 	bytesread = print_dec(va_arg(aptr, char));
	// else if (c == 'i')
	// 	bytesread = print_integer(va_arg(aptr, char));
	// else if (c == 'u')
	// 	bytesread = print_udec(va_arg(aptr, char));
	// else if (c == 'x')
	// 	bytesread = print_hexlow(va_arg(aptr, char));
	// else if (c == 'X')
	// 	bytesread = print_hexup(va_arg(aptr, char));
	// else if (c == '%')
	// 	bytesread = print_percent(va_arg(aptr, char));
	return (bytesread);
}

int	ft_printf(const char *format, ...)
{
	int		bytesread;
	va_list	aptr;

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

int	main()
{
	char	c = 'o';
	char	*s = "str";
	int	bytesread = ft_printf("char:%c, string: %s", c, s);
	printf("\n\ntotal bytes read: %d\n", bytesread);
	return (0);
}
