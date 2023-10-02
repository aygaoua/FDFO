# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 01:13:53 by azgaoua           #+#    #+#              #
#    Updated: 2023/10/02 14:47:38 by azgaoua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BNS_NAME = fdf_bonus

OBJS = fdf.o main.o maps_reader.o draw_things.o init.o
BNSOBJS = fdf_bonus.o main_bonus.o maps_reader_bonus.o draw_things_bonus.o \
			rotation_bonus.o

FILES = fdf.c main.c maps_reader.c draw_things.c init.c
BNSFILES = fdf_bonus.c main_bonus.c maps_reader_bonus.c draw_things_bonus.c \
			rotation_bonus.c

CC = cc

RM = rm -rf

FLGS = -Wall -Wextra -Werror

all :  $(NAME)

%.o: %.c fdf.h ./printo/*.c ./libft/*.c ./printo/*.h ./libft/*.h
	@$(CC) $(FLGS) -Imlx -c $< -o $@

$(NAME) :  $(OBJS)
	@echo "------>making the FDF<------"
	@cd libft && make && make clean
	@cd printo && make && make clean
	@$(CC) $(FLGS) $(OBJS) libft/libft.a printo/myprintf.a -lmlx -framework OpenGL -framework AppKit  -o $(NAME)
	@echo "--------->FDF Done<---------"

bonus :  $(BNS_NAME)

$(BNS_NAME): $(BNSOBJS)
	@echo "----->making the FDF_BONUS<-----"
	@cd libft && make && make clean
	@cd printo && make && make clean
	@$(CC) $(FLGS) $(BNSOBJS) libft/libft.a printo/myprintf.a -lmlx -framework OpenGL -framework AppKit  -o $(BNS_NAME)
	@echo "----->FDF_BONUS Done<-----"

clean:
	@echo " clean all this FILES if exist: $(OBJS) $(BNSOBJS)"
	@$(RM) $(OBJS) $(BNSOBJS)

fclean:  clean
	@echo "		+ that --> $(NAME) $(BNS_NAME) printo/myprintf.a libft/libft.a"
	@$(RM) $(NAME) $(BNS_NAME) printo/myprintf.a libft/libft.a

re: fclean all