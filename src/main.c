#include "../inc/push_swap.h"

void	free_split(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

static void	handle_two_args(t_node **a, char *arg)
{
	char	**split_argv;

	split_argv = ft_split(arg, ' ');
	if (!split_argv || !split_argv[0])
	{
		free_split(split_argv);
		int i = write(2, "Error\n", 6);
		(void)i;
		exit(1);
	}
	init_stack_a(a, split_argv);
	free_split(split_argv);
}

static void	solve_small(t_node **a)
{
	t_sim	s;

	s.a = *a;
	s.b = NULL;
	init_ops(&s.ops);
	if (stack_len(s.a) == 2)
		op_sa(&s);
	else
		sort_three(&s);
	print_ops(&s.ops);
	free(s.ops.arr);
	*a = s.a;
}

int	main(int argc, char **argv)
{
	t_node	*a;

	a = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
	{
		int i = write(2, "Error\n", 6);
		(void)i;
		return (1);
	}
	else if (argc == 2)
		handle_two_args(&a, argv[1]);
	else
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) <= 3)
			solve_small(&a);
		else
			run_portfolio(a);
	}
	free_stack(&a);
	return (0);
}
