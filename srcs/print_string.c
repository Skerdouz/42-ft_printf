#include "../includes/ft_printf.h"

int	print_string(char *str)
{
	int	bytesread;

	bytesread = 0;
	while (*str)
	{
		write(1, str++, 1);
		bytesread++;
	}
	return (bytesread);
}