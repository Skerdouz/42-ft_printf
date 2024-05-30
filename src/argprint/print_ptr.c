#include "ft_printf.h"

int	print_ptr(void *ptr)
{
	int			bytesread;

	bytesread = 0;
	if (!ptr)
		return (print_str("(nil)"));
	bytesread = write(1, "0x", 2);
	bytesread += print_hex((size_t)ptr, 'x');
	return (bytesread);
}