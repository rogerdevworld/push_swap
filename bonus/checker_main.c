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

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	exec_instruction(t_stack_node **a, t_stack_node **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, false);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, false);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, false);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, false);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a, false);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, false);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, false);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, false);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, false);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, false);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, false);
	else
	{
		free(line);
		free_stack(a);
		free_stack(b);
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	read_and_exec(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_instruction(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (stack_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	read_and_exec(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
