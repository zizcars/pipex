NAME=pipex
CFLAGS= -Wall -Wextra -Werror #-fsanitize=address
FT_LIBS= ft_printf/libftprintf.a libft/libft.a

CFILES= pipex.c \
		get_next_line_utils.c \
		get_next_line.c \
		split_cmd.c \
		exec.c 

CBFILES=pipex_bonus.c \
		get_next_line_utils_bonus.c \
		get_next_line_bonus.c \
		split_cmd_bonus.c \
		exec_bonus.c 

OFILES=$(CFILES:.c=.o)
BFILES=$(CBFILES:.c=.o)

%.o:%.c pipex.h pipex_bonus.h
	cc $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OFILES)
	@cd libft && make && make bonus
	@cd ft_printf && make
	cc $(CFLAGS) $(OFILES) $(FT_LIBS) -o $(NAME)

# libs:
bonus: $(BFILES)
	@cd libft && make && make bonus
	@cd ft_printf && make
	cc $(CFLAGS) $(BFILES) $(FT_LIBS) -o $(NAME)

clean:
	@rm -f $(OFILES) $(BFILES)
	@cd libft && make clean
	@cd ft_printf && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean
	@cd ft_printf && make fclean

re: fclean all

.PHONY: clean libs
