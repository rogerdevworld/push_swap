#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					rank;
	int					index;
	int					push_cost;
	int					move_type;
	bool				keep;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* Parsing & Errors */
int				error_syntax(char *str);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
void			init_stack_a(t_stack_node **a, char **argv);
char			**ft_split(char *s, char c);

/* Stack Utils */
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			current_index(t_stack_node *stack);

/* LIS & Ranking */
void			assign_ranks(t_stack_node *a);
void			mark_lis(t_stack_node *a);

/* Turk Return (B -> A) */
t_stack_node	*get_cheapest_b(t_stack_node *a, t_stack_node *b);
void			exec_cheapest_b(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);

/* Operations */
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

/* Algorithms */
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
