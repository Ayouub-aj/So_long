#include "so_long.h"

int	ft_close(t_unit *info)
{
	(void)info;
	exit(0);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

void	printf_error_exit(char *str)
{
	ft_printf("%s\n", &str);
	exit(0);
}
