#include "ft_printf.h"

size_t	ft_string(char *s)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (ft_lenghtofstring("(null)"));
	i = 0;
	j = ft_lenghtofstring(s);
	while (i < j)
	{
		write(1, s++, 1);
		i++;
	}
	return (i);
}
