NAME=pipex
CFLAGS= -Wall -Wextra -Werror -fsanitize=address
FT_LIBS= ft_printf/libftprintf.a libft/libft.a
CFILES= main.c \
		get_next_line_utils.c \
		get_next_line.c \

OFILES=$(CFILES:.c=.o)

%.o:%.c pipex.h
	cc $(CFLAGS) -c $<

all: $(NAME)

$(NAME): libs $(OFILES)
	@cc $(CFLAGS) $(OFILES) $(FT_LIBS) -o $(NAME)

libs:
	@cd libft && make && make bonus
	@cd ft_printf && make

clean:
	@rm -f $(OFILES)
	@cd libft && make clean
	@cd ft_printf && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean
	@cd ft_printf && make fclean

re: fclean all

.PHONY: clean libs

#delete this
# -------------------------------
TST= test.c \
	get_next_line_utils.c \
	get_next_line.c \

OTST=$(TST:.c=.o)
test:  libs $(OTST)
	cc $(CFLAGS) $(OTST) $(FT_LIBS) -o test
# -------------------------------------------