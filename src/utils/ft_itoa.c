#include "ft_printf.h"

static int	sizecalc(long nb, int neg)
{
	int	size;

	size = 0;
	if (!nb)
		return (1);
	if (neg)
		size++;
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static void	convert(char *str, long nb, int size, int neg)
{
	if (!nb)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	str[size] = '\0';
	while (size > 0)
	{
		str[--size] = (nb % 10) + '0';
		nb /= 10;
	}
	if (neg)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		neg;
	long	nb;

	nb = n;
	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	size = sizecalc(nb, neg);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	convert(str, nb, size, neg);
	return (str);
}
