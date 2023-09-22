# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 01:13:53 by azgaoua           #+#    #+#              #
#    Updated: 2023/09/19 22:03:23 by azgaoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJS = fdf.o main.o maps_reader.o draw_things.o

FILES = fdf.c main.c maps_reader.c draw_things.c

CC = cc

RM = rm -rf

FLGS = -Wall -Wextra -Werror

all :  $(NAME)

%.o: %.c fdf.h
	@echo " creating : $@  (from this : >> $< <<) \n\\---***___***---***___***---***___***---***___***---\\"
	@$(CC) $(FLGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) 
	@echo " making the FDFO"
	cd libft && make && make clean
	@$(CC) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@echo " clean all this FILES if exist: $(OBJS)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "		+ that --> $(NAME)"
	@$(RM) $(NAME)

re: fclean all