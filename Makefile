# ====================================
#  ____  _          _               
# |  _ \(_)___  ___| |_ _ __ _   _  
# | |_) | / __|/ __| __| '__| | | | 
# |  __/| \__ \ (__| |_| |  | |_| | 
# |_|   |_|___/\___|\__|_|   \__, | 
#                             |___/ 
#         PIPEX PROJECT
# ====================================

# === Colors ===
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RED = \033[0;31m
RESET = \033[0m

# === Compiler and Flags ===
CC = cc
CFLAGS = -Wall -Wextra -Werror

# === Project Name ===
NAME = pipex

# === Directories ===
SRC_DIR = src
BONUS_DIR = bonus
INCLUDES = includes
LIB_DIR = lib

# === Files ===
FT_LIBS = $(LIB_DIR)/libft.a

CFILES = $(SRC_DIR)/main.c \
         $(SRC_DIR)/split_cmd.c \
         $(SRC_DIR)/exec.c

CBFILES = $(BONUS_DIR)/main_bonus.c \
          $(BONUS_DIR)/split_cmd_bonus.c \
          $(BONUS_DIR)/exec_bonus.c \
          $(BONUS_DIR)/here_doc_bonus.c

OFILES = $(CFILES:.c=.o)
BFILES = $(CBFILES:.c=.o)

# === Rules ===
%.o: %.c $(INCLUDES)/pipex.h $(INCLUDES)/pipex_bonus.h
	@echo "$(YELLOW)[Compiling]$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	@echo "$(GREEN)[Building]$(RESET) Mandatory part..."
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(OFILES) $(FT_LIBS) -o $(NAME)
	@echo "$(BLUE)[Success]$(RESET) Executable created: $(NAME)"

bonus: $(BFILES)
	@echo "$(GREEN)[Building]$(RESET) Bonus part..."
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(BFILES) $(FT_LIBS) -o $(NAME)
	@echo "$(BLUE)[Success]$(RESET) Bonus executable created: $(NAME)"

clean:
	@echo "$(RED)[Cleaning]$(RESET) Object files..."
	@rm -f $(OFILES) $(BFILES)
	@make clean -C $(LIB_DIR)
	@echo "$(BLUE)[Done]$(RESET) Cleaned object files."

fclean: clean
	@echo "$(RED)[Cleaning]$(RESET) Executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
	@echo "$(BLUE)[Done]$(RESET) All cleaned."

re: fclean all

.PHONY: all bonus clean fclean re
