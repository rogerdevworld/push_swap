NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinc

SRC_DIR		= src/
OBJ_DIR		= obj/
BONUS_DIR	= bonus/

SRCS		= main.c ft_split.c utils.c stack_init.c error_handling.c \
			  stack_utils.c lis_rank.c cost_b_to_a.c exec_b_to_a.c \
			  sort_three.c sort_stacks.c \
			  swap.c push.c rotate.c rev_rotate.c

BONUS_SRCS	= checker_main.c utils.c ft_split.c stack_init.c error_handling.c \
			  stack_utils.c swap.c push.c rotate.c rev_rotate.c \
			  get_next_line.c

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(OBJ_DIR), $(BONUS_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c inc/push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c inc/push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
