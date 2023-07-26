#include "ft_printf.h"

size_t	ft_char(const int c)
{
	write(1, &c, 1);
	return (1);
}
