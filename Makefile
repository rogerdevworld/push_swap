# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 12:58:52 by rmarrero          #+#    #+#              #
#    Updated: 2025/02/17 11:55:01 by rmarrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# --- Mandatory --- #
NAME = push_swap
SRC_DIR = ./src/
OBJ_DIR = ./obj

# Listado de archivos fuente
SRCS =	$(SRC_DIR)push_swap.c $(SRC_DIR)push_swap_utils.c \
		$(SRC_DIR)movements/push.c $(SRC_DIR)movements/reverse.c $(SRC_DIR)movements/swap.c $(SRC_DIR)movements/rotate.c \
    	$(SRC_DIR)sort/sort_three.c $(SRC_DIR)sort/sort_four.c $(SRC_DIR)sort/sort_five.c $(SRC_DIR)sort/sort_six.c $(SRC_DIR)sort/sort_big.c $(SRC_DIR)sort/sort_big/sort_big_utils.c $(SRC_DIR)sort/sort_big/sort_fixed.c \
		$(SRC_DIR)utils/checker.c $(SRC_DIR)utils/parsing.c $(SRC_DIR)utils/stacks.c $(SRC_DIR)utils/visual.c

# Convertimos los archivos .c en .o en la carpeta de objetos
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

HEADER = ./include/push_swap.h
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./include
RM = rm -rf

LIBFT = ./libft
EX_LIB = $(LIBFT)/libft.a

# Color
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
RESET   = \033[0m

# Regla principal
all: libs $(NAME) 

libs:
	@make -C $(LIBFT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) \
	$(OBJ_DIR)/movements \
	$(OBJ_DIR)/sort \
	$(OBJ_DIR)/sort/sort_big \
	$(OBJ_DIR)/utils

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(HEADER) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(EX_LIB) $(OBJS)
	@echo "$(GREEN)Compilando push_swap...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME) > /dev/null
	@echo "$(BLUE)"
	@echo "$(YELLOW)           ($(RESET)__$(YELLOW))\           $(RESET)"
	@echo "$(YELLOW)           ($(RESET)oo$(YELLOW))\\________  $(RESET)"
	@echo "$(RESET)           /|| \\        \\ push_swap ready$(RESET)"
	@echo "$(RESET)              ||------w | $(RESET)"
	@echo "$(RESET)              ||       || $(RESET)"
	@echo "$(YELLOW)THE COW MAKES MUUUUUUUUUU!$(RESET)"
	@echo "$(YELLOW)push_swap compilado con éxito!$(RESET)"

clean:
	@echo "$(GREEN)Eliminando archivos objeto...$(RESET)"
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: clean
	@echo "$(GREEN)Eliminando ejecutable y librerías...$(RESET)"
	$(RM) $(NAME) 
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
