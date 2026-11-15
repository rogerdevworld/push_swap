NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinc

SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS		= main.c ft_split.c stack_init.c error_handling.c \
			  stack_utils.c lis_rank.c cost_b_to_a.c exec_b_to_a.c \
			  sort_three.c sort_stacks.c \
			  swap.c push.c rotate.c rev_rotate.c

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c inc/push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
