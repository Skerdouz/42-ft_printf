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
		bytesread = print_hex(va_arg(aptr, size_t), format);
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
// int main() {
// 	int *ptr1 = NULL;
// 	int *ptr2 = (int *)0x0;
// 	int x = 42;
// 	int *ptr3 = &x;

// 	ft_printf("result: %p\n", (void *)ptr1);
// 	printf("expected: %p\n\n", (void *)ptr1);

// 	ft_printf("result: %p\n", (void *)ptr2);
// 	printf("expected: %p\n\n", (void *)ptr2);

// 	ft_printf("result: %p\n", (void *)ptr3);
// 	printf("expected: %p\n\n", (void *)ptr3);

// 	return 0;
// }
