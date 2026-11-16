NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3 -Iinc

SRC_DIR		= src/
BONUS_DIR	= bonus/
OBJ_DIR		= obj/

COMMON_SRCS	= ft_split.c stack_init.c error_handling.c stack_utils.c \
			  index_rank.c ops_recorder.c ops_swap_push.c ops_rotate.c \
			  ops_rev_rotate.c

MAIN_SRCS	= main.c dp_lis.c push_chunks.c cost_b_to_a.c \
			  exec_b_to_a.c portfolio.c

BONUS_SRCS	= checker_main.c checker_ops_extra.c get_next_line.c

OBJS		= $(addprefix $(OBJ_DIR), $(COMMON_SRCS:.c=.o) $(MAIN_SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(OBJ_DIR), $(COMMON_SRCS:.c=.o) $(BONUS_SRCS:.c=.o))

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
