#include "ft_printf.h"

int	print_ptr(void *ptr)
{
	int	bytesread;

	bytesread = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	bytesread = write(1, "0x", 2);
	bytesread += print_hex((size_t)ptr, 'x');
	return (bytesread);
}
