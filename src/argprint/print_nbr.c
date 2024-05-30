#include "ft_printf.h"

int	print_nbr(int nbr)
{
	char	*snbr;
	int		bytesread;

	bytesread = 0;
	snbr = ft_itoa(nbr);
	bytesread = print_str(snbr);
	return (free(snbr), bytesread);
}
