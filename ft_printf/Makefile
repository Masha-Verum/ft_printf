# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/28 10:50:13 by mbantam           #+#    #+#              #
#    Updated: 2020/07/28 11:28:50 by mbantam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
OBFLG = -Wall -Wextra -Werror
HEADER = ft_printf.h
SRC =	ft_printf.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_itoa.c\
		ft_memcpy.c\
		ft_putstr.c\
		ft_strchr.c\
		ft_strlen.c\
		parse_format.c\
		print_c_s.c\
		print_int.c\
		print_type.c\
		print_u_x.c\
		print_width.c\
		
OBJ =   ft_printf.o\
		ft_bzero.o\
		ft_calloc.o\
		ft_itoa.o\
		ft_memcpy.o\
		ft_putstr.o\
		ft_strchr.o\
		ft_strlen.o\
		parse_format.o\
		print_c_s.o\
		print_int.o\
		print_type.o\
		print_u_x.o\
		print_width.o\

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CC) -c $(SRC) $(OBFLG)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all
