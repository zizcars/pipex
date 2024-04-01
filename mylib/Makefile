# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 17:20:23 by Achakkaf          #+#    #+#              #
#    Updated: 2024/03/31 22:48:13 by achakkaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS  = -Wall -Wextra -Werror
NAME = mylib.a 

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
			ft_putnbr_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_printf.c \
			ft_putaddress.c \
			ft_puthex.c \
			ft_putnbr.c \
			ft_uputnbr.c \
			ft_putchar.c \
			ft_putstr.c \
			get_next_line.c \
			get_next_line_utils.c 

OFILES = $(CFILES:.c=.o)

all : $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)

%.o:%.c libft.h ft_printf.h get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: clean 