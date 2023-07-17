/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_start.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 11:29:22 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/02 21:35:00 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../pushswap.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int	check_stacks(t_stacks *stk, t_tops *top)
{
	int	i;

	i = top->a;
	if (top->b != -1)
		return (0);
	while (i > 0)
	{
		if (stk->stack_a[i] > stk->stack_a[i - 1])
			return (0);
		--i;
	}
	return (1);
}

void	malloc_size(int argc, char **argv, t_tops *top)
{
	char	**argenv;
	int		len;

	top->a = -1;
	top->b = -1;
	argenv = ft_split(argv[1], ' ');
	len = lenarg(argenv);
	if (len >= 2 && argc == 2)
		top->malsize = len;
	else if (argc > 2 && len == 1)
		top->malsize = argc - 1;
	else
	{
		top->malsize = 0;
		if (len)
			checker(&len, top, argenv[0]);
	}
	ft_freee(argenv);
}

int	check_cmd(char *line, t_stacks *stk, t_tops *top, int i)
{
	if (!i && !ft_strncmp(line, "ra\n", 4))
		i = rota(&stk->stack_a, top->a, 'c');
	else if (!i && !ft_strncmp(line, "rb\n", 4))
		i = rotb(&stk->stack_b, top->b, 'c');
	else if (!i && !ft_strncmp(line, "rr\n", 4))
		i = rotabs(&stk->stack_a, &stk->stack_b, top, 'c');
	else if (!i && !ft_strncmp(line, "rra\n", 5))
		i = revrota(&stk->stack_a, top->a, 'c');
	else if (!i && !ft_strncmp(line, "rrb\n", 5))
		i = revrotb(&stk->stack_b, top->b, 'c');
	else if (!i && !ft_strncmp(line, "rrr\n", 5))
		i = revrotabs(&stk->stack_a, &stk->stack_b, top, 'c');
	else if (!i && !ft_strncmp(line, "sa\n", 4))
		i = swapa(&stk->stack_a, top->a, 'c');
	else if (!i && !ft_strncmp(line, "sb\n", 4))
		i = swapb(&stk->stack_b, top->b, 'c');
	else if (!i && !ft_strncmp(line, "ss\n", 4))
		i = swaps(&stk->stack_a, &stk->stack_b, top, 'c');
	else if (!i && !ft_strncmp(line, "pa\n", 4))
		i = (pusha(stk, top, 'e'));
	else if (!i && !ft_strncmp(line, "pb\n", 4))
		i = (pushb(stk, top, 'e'));
	return (i);
}

int	start_to_check(t_stacks *stk, t_tops *top)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_cmd(line, stk, top, 0))
		{
			write(1, "KO\n", 3);
			return (free(line), 0);
		}
		free(line);
		line = get_next_line(0);
	}
	if (!check_stacks(stk, top))
	{
		write(1, "KO\n", 3);
		return (0);
	}
	write(1, "OK\n", 3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stk;
	t_tops		top;

	if (argc < 2)
		return (0);
	malloc_size(argc, argv, &top);
	stk.stack_a = malloc((top.malsize) * sizeof(int));
	if (!stk.stack_a)
		return (0);
	stk.stack_b = malloc((top.malsize) * sizeof(int));
	if (!stk.stack_b)
		return (free(stk.stack_a), 0);
	argorstr(argc, argv, &top, &stk.stack_a);
	if (!stk.stack_a || !top.malsize)
		return (freeab(stk.stack_a, stk.stack_b));
	start_to_check(&stk, &top);
	freeab(stk.stack_a, stk.stack_b);
	return (0);
}
