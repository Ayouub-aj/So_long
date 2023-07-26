NAME =	libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = 	ft_char.c ft_decimal.c \
		ft_hex.c ft_pointer.c \
		ft_printf.c \
		ft_string.c \
		utils.c \


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : ft_printf.h
	cc $(FLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all

.PHONY : all clean flclean re 
