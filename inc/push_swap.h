#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

# define OP_SA 1
# define OP_SB 2
# define OP_SS 3
# define OP_PA 4
# define OP_PB 5
# define OP_RA 6
# define OP_RB 7
# define OP_RR 8
# define OP_RRA 9
# define OP_RRB 10
# define OP_RRR 11

typedef struct s_node
{
	int				nbr;
	int				rank;
	int				index;
	int				cost;
	int				route;
	bool			keep;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_ops
{
	int	*arr;
	int	len;
	int	cap;
}	t_ops;

typedef struct s_sim
{
	t_node	*a;
	t_node	*b;
	t_ops	ops;
	int		bands;
	bool	use_lis;
	bool	rrr_bias;
}	t_sim;

/* Parsing & Errors */
int		error_syntax(char *str);
int		error_duplicate(t_node *a, int n);
void	free_stack(t_node **stack);
void	free_errors(t_node **a);
void	init_stack_a(t_node **a, char **argv);
char	**ft_split(char *s, char c);
void	free_split(char **argv);

/* Stack Utils */
int		stack_len(t_node *stack);
t_node	*find_last(t_node *stack);
bool	stack_sorted(t_node *stack);
t_node	*find_min(t_node *stack);
t_node	*find_max(t_node *stack);
void	current_index(t_node *stack);
t_node	*clone_stack(t_node *src);

/* Operations & Recorder */
void	init_ops(t_ops *ops);
void	record_op(t_ops *ops, int op);
void	optimize_ops(t_ops *ops);
void	print_ops(t_ops *ops);
void	op_sa(t_sim *s);
void	op_sb(t_sim *s);
void	op_ss(t_sim *s);
void	op_pa(t_sim *s);
void	op_pb(t_sim *s);
void	op_ra(t_sim *s);
void	op_rb(t_sim *s);
void	op_rr(t_sim *s);
void	op_rra(t_sim *s);
void	op_rrb(t_sim *s);
void	op_rrr(t_sim *s);

/* DP Circular LIS & Ranking */
void	assign_ranks(t_node *a);
void	mark_dp_lis(t_node *a);
void	mark_keep_three(t_node *a);

/* Chunk Push (A -> B) & Turk Return (B -> A) */
void	push_chunks(t_sim *s, int n);
t_node	*get_cheapest_b(t_sim *s);
void	exec_cheapest_b(t_sim *s, t_node *ch);

/* Portfolio Engine & Small Sorts */
void	sort_three(t_sim *s);
void	run_portfolio(t_node *orig_a);

/* GNL for Bonus */
char	*get_next_line(int fd);

#endif
