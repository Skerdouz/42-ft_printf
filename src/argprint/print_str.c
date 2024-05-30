#include "ft_printf.h"

int	print_str(char *str)
{
	int	bytesread;

	bytesread = 0;
	if (!str)
		return (0);
	while(*str)
		bytesread += print_char((int)*(str++));
	return (bytesread);
}