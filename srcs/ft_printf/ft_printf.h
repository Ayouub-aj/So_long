#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	ft_char(const int c);
size_t	ft_string(char *s);
int		ft_decimal(unsigned long int number);
int		ft_hex(unsigned int numb, const char *type);
int		ft_pointer(unsigned long int num);
int		ft_printf(const char *format, ...);
void	ft_putstr_filed(char *string, int fd);
size_t	ft_lenghtofstring(char *string);
char	*ft_inttoarray(int n);
#endif
