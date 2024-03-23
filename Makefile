NAME=pipex
CFLAGS= -Wall -Wextra -Werror #-fsanitize=address
FT_LIBS= ft_printf/libftprintf.a libft/libft.a
CFILES= main.c \
		get_next_line_utils.c \
		get_next_line.c \
		pipex_tooles.c \
		exec.c \
		# split_cmd.c 

OFILES=$(CFILES:.c=.o)

%.o:%.c pipex.h
	cc $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OFILES)
	@cd libft && make && make bonus
	@cd ft_printf && make
	cc $(CFLAGS) $(OFILES) $(FT_LIBS) -o $(NAME)

# libs:
	

clean:
	@rm -f $(OFILES)
	@cd libft && make clean
	@cd ft_printf && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean
	@cd ft_printf && make fclean

re: fclean all


#delete this
# -------------------------------
TST= test.c \
	get_next_line_utils.c \
	get_next_line.c \
	# split_cmd.c 

OTST=$(TST:.c=.o)
test: $(OTST)
	@cd libft && make && make bonus
	@cd ft_printf && make
	cc $(CFLAGS) $(OTST) $(FT_LIBS) -o test
# -------------------------------------------

.PHONY: clean libs test
