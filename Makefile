NAME=pipex
CFLAGS= -Wall -Wextra -Werror #-fsanitize=address
FT_LIBS= mylib/mylib.a

CFILES= mandatory/main.c \
		mandatory/split_cmd.c \
		mandatory/exec.c 

CBFILES=bonus/main_bonus.c \
		bonus/split_cmd_bonus.c \
		bonus/exec_bonus.c \
		bonus/here_doc_bonus.c 

OFILES=$(CFILES:.c=.o)
BFILES=$(CBFILES:.c=.o)

%.o:%.c mandatory/pipex.h bonus/pipex_bonus.h
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	@make -C mylib
	cc $(CFLAGS) $(OFILES) $(FT_LIBS) -o $(NAME)

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

.PHONY: clean libs bonus
