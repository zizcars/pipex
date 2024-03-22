
CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC =	ft_printf.c \
		ft_putchar.c \
		ft_puthex.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_putnbr.c \
		ft_putaddress.c \
		ft_uputnbr.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@ar rc $(NAME) $(OBJ)
	
%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: re fclean clean all 
