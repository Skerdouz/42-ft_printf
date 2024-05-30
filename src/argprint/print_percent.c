#include "ft_printf.h"

int	print_percent()
{
	return (write(1, "%", 1));
}