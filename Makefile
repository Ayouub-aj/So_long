# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayidbelh <ayidbelh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 15:37:36 by ayidbelh          #+#    #+#              #
#    Updated: 2022/07/01 16:04:27 by ayidbelh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------#
#           EXECUTABLES		       #
#----------------------------------#
	
NAME		:= 	so_long

#----------------------------------#
#			  SOURCES			   #
#----------------------------------#

SRC			:=  ./srcs/mandatory/so_long.c \
				./srcs/mandatory/map_error_checks.c \
				./srcs/mandatory/draw_map_chars.c \
				./srcs/mandatory/draw_player.c \
				./srcs/mandatory/get_next_line.c \
				./srcs/mandatory/map_get_next_line.c \
				./srcs/mandatory/check_on_moves.c \
				./srcs/mandatory/control_player.c \
				./srcs/mandatory/image_sourcing.c \
				./srcs/mandatory/utilities.c

#----------------------------------#
#			  LIBRARIES			   #
#----------------------------------#

LIBFT		:=	./srcs/ft_printf/libftprintf.a

#----------------------------------#
#			 OBJECTS			   #
#----------------------------------#
OBJ			:= 	$(SRC:.c=.o)

#----------------------------------#
#			  FLAGS				   #
#----------------------------------#

FLAGS		:= 	-Wall -Wextra -Werror -Imlx
MLX			:=	-lmlx -framework OpenGL -framework AppKit
CC			:= 	gcc
RM			:=	rm -rf

#----------------------------------#
#		 COMPILATION/RULES         #
#----------------------------------#

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(LIBFT) $(OBJ) $(MLX) -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C ./srcs/ft_printf

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	make -C ./srcs/ft_printf fclean

fclean: clean
	$(RM) $(NAME) $(BB)

re: fclean all

norm:
	norminette

.PHONY: all clean fclean re norm
