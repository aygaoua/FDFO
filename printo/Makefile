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
			$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJ)
			@ar rc $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)
fclean: clean
		@$(RM) $(NAME)
re: fclean all
