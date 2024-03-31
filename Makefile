NAME=pipex
CFLAGS= -Wall -Wextra -Werror #-fsanitize=address
FT_LIBS= mylib/mylib.a

CFILES= pipex.c \
		split_cmd.c \
		exec.c 

CBFILES=pipex_bonus.c \
		split_cmd_bonus.c \
		exec_bonus.c 

OFILES=$(CFILES:.c=.o)
BFILES=$(CBFILES:.c=.o)

%.o:%.c pipex.h pipex_bonus.h
	cc $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OFILES)
	@make -C mylib
	cc $(CFLAGS) $(OFILES) $(FT_LIBS) -o $(NAME)

# libs:
bonus: $(BFILES)
	@Make -C mylib
	cc $(CFLAGS) $(BFILES) $(FT_LIBS) -o $(NAME)

clean:
	@rm -f $(OFILES) $(BFILES)
	@make clean -C mylib

fclean: clean
	@rm -f $(NAME)
	@make fclean -C mylib


re: fclean all

.PHONY: clean libs
