#include "ft_printf.h"

int	ft_decimal(unsigned long int number)
{
	char	*res;
	int		counter;

	res = ft_inttoarray(number);
	ft_putstr_filed(res, 1);
	counter = ft_lenghtofstring(res);
	free (res);
	return (counter);
}
