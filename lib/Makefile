# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 17:20:23 by Achakkaf          #+#    #+#              #
#    Updated: 2024/03/17 19:34:36 by Achakkaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RED = \033[0;31m
RESET = \033[0m

CC = cc
CFLAGS  = -Wall -Wextra -Werror
NAME = libft.a 

CFILES =	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c 

BFILES =	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			

OFILES = $(CFILES:.c=.o)
OBFILES = $(BFILES:.c=.o)

all : $(NAME)

$(NAME): $(OFILES)
	@echo "$(GREEN)[Compiling]$(RESET) Creating $(NAME)..."
	@ar rc $(NAME) $(OFILES)
	@echo "$(BLUE)[Success]$(RESET) $(NAME) built!"

%.o:%.c libft.h
	@echo "$(YELLOW)[Compiling]$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus : $(OBFILES)
	@echo "$(GREEN)[Compiling]$(RESET) Creating bonus: $(BNAME)..."
	@ar rc $(NAME) $(OBFILES)
	@echo "$(BLUE)[Success]$(RESET) $(BNAME) built!"

clean : 
	@echo "$(RED)[Cleaning]$(RESET) Object files..."
	@rm -f $(OFILES) $(OBFILES)
	@echo "$(BLUE)[Done]$(RESET) Object files removed."

fclean: clean
	@echo "$(RED)[Cleaning]$(RESET) Executables..."
	@rm -f $(NAME)
	@echo "$(BLUE)[Done]$(RESET) All cleaned."

re : fclean all

.PHONY: all clean fclean re bonus