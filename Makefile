# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 12:58:52 by rmarrero          #+#    #+#              #
#    Updated: 2025/01/31 18:12:07 by rmarrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# --- Mandatory --- #
NAME = push_swap
SRC = ./src/
OBJS = ./src/push_swap.c ./src/push_swap_utils.c
MBJS = ./src/movements/push.c ./src/movements/reverse.c ./src/movements/swap.c ./src/movements/rotate.c
SBJS = ./src/sort/sort_three.c ./src/sort/sort_four.c ./src/sort/sort_five.c ./src/sort/sort_six.c ./src/sort/sort_big.c ./src/sort/sort_big/sort_big_utils.c ./src/sort/sort_big/sort_fixed.c
UBJS = ./src/utils/checker.c ./src/utils/parsing.c ./src/utils/stacks.c ./src/utils/visual.c
ALLOBJS = $(OBJS) $(MBJS) $(SBJS) $(UBJS)  ./libft/libft.a
HEADER = ./include/push_swap.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

TESTER = test.sh

#color
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
RESET   = \033[0m

#Reglas
all: $(NAME)

$(NAME): $(HEADER) Makefile
	make all -C libft
	@echo "$(GREEN)Compilando push_swap...$(RESET)"
	$(CC)  $(ALLOBJS) -o $(NAME) 
	@echo "$(BLUE)"
	@echo "$(YELLOW)           ($(RESET)__$(YELLOW))\           $(RESET)"
	@echo "$(YELLOW)           ($(RESET)oo$(YELLOW))\\________  $(RESET)"
	@echo "$(RESET)           /|| \\        \\ push_swap READY$(RESET)"
	@echo "$(RESET)              ||------w | $(RESET)"
	@echo "$(RESET)              ||       || $(RESET)"
	@echo "$(YELLOW)THE COW MAKES MUUUUUUUUUU!$(RESET)"
	@echo "$(RESET)"

test:
	git clone https://github.com/your-username/push_swap_tester.git
	cd push_swap_tester
	chmod +x tester_push_swap.sh
	./tester_push_swap.sh

clean:
	@echo "$(GREEN)eliminado...$(RESET)"
	$(RM) .o
	make clean -C libft

fclean: clean
	@echo "$(GREEN)eliminando todo...$(RESET)"
	$(RM) $(NAME)
	make fclean -C libft
	
re: fclean all

.PHONY : all clean fclean re
