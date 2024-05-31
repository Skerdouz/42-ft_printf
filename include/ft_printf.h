/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrahins <lbrahins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:34 by lbrahins          #+#    #+#             */
/*   Updated: 2024/05/31 09:45:14 by lbrahins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

//main
int		ft_printf(const char *format, ...);
//argsprint
int		print_char(int c);
int		print_str(char *str);
int		print_nbr(int nbr);
int		print_unbr(unsigned int nbr);
int		print_percent(void);
int		print_hex(size_t nbr, const char format);
int		print_ptr(void *ptr);
// utils
char	*ft_itoa(int n);

#endif
