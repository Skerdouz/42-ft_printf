#include "ft_printf.h"

int	print_percent(void)
{
	return (write(1, "%", 1));
}
