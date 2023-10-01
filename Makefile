# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 01:13:53 by azgaoua           #+#    #+#              #
#    Updated: 2023/09/29 18:43:18 by azgaoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJS = fdf.o main.o maps_reader.o draw_things.o rotation.o

FILES = fdf.c main.c maps_reader.c draw_things.c rotation.c

CC = cc

RM = rm -rf

FLGS = -Wall -Wextra -Werror

all :  $(NAME)

$(NAME) : $(OBJS)
	@echo " making the FDFO"
	cd libft && make bonus && make clean
	cd printo && make && make clean
	@$(CC) $(FLGS) $(OBJS) libft/libft.a printo/myprintf.a -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

%.o: %.c fdf.h ./printo/ft_printf.h ./libft/libft.h
	@echo " creating : $@  (from this : >> $< <<) \n\\---***___***---***___***---***___***---***___***---\\"
	@$(CC) $(FLGS) -Imlx -c $< -o $@

clean:
	@echo " clean all this FILES if exist: $(OBJS)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "		+ that --> $(NAME)"
	@$(RM) $(NAME)

re: fclean all