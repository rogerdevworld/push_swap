#include "../inc/push_swap.h"

static void	free_split(char **argv)
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

static void	handle_two_args(t_stack_node **a, char *arg)
{
	char	**split_argv;

	split_argv = ft_split(arg, ' ');
	if (!split_argv || !split_argv[0])
	{
		free_split(split_argv);
		write(2, "Error\n", 6);
		exit(1);
	}
	init_stack_a(a, split_argv);
	free_split(split_argv);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
		handle_two_args(&a, argv[1]);
	else
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
