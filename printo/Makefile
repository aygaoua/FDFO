# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 23:48:44 by azgaoua           #+#    #+#              #
#    Updated: 2023/10/02 14:47:21 by azgaoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_hexa.c			\
		ft_putnbr.c		\
		ft_putstr.c		\
		ft_printf.c		\
		ft_putchar.c	\
		ft_uphexa.c		\
		ft_pointer.c	\
		ft_unbr.c		\
		ft_strlen.c		\

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c ft_printf.h
			@$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJ)
			@ar rc $(NAME) $(OBJ)
			@echo "-----> ft_printf Done <-----"

clean:
		@$(RM) $(OBJ)
fclean: clean
		@$(RM) $(NAME)
re: fclean all
