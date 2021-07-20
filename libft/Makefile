# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 10:47:47 by apires-d          #+#    #+#              #
#    Updated: 2021/07/20 15:56:56 by apires-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAG = -Wall -Wextra -Werror

OBJ = ft_atoi.o ft_bzero.o ft_calloc.o ft_itoa.o ft_putchar_fd.o ft_putnbr_fd.o ft_putstr_fd.o \
	ft_strdup.o ft_strlen.o ft_substr.o ft_len_nbr.o ft_len_uns_nbr.o ft_int_to_hex.o ft_isdigit.o

all: $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) *.o

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
