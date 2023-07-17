/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 0002/12/09 13:01:00 by top2 by kyu   #+#    #+#                 */
/*   Updated: 2023/02/05 11:58:34 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../pushswap.h"
#include "../libft/libft.h"

void	smallsorta(int **stack, char e, int top)
{
	if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
	{
		swapa(stack, top, e);
		rota(stack, top, e);
	}
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
		rota(stack, top, e);
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
	{
		swapa(stack, top, e);
		revrota(stack, top, e);
	}
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
		swapa(stack, top, e);
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
		revrota(stack, top, e);
}

void	smallsortb(int **stack, int top)
{
	if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapb(stack, top, 'b');
		rotb(stack, top, 'b');
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
		rotb(stack, top, 'b');
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
	{
		swapb(stack, top, 'b');
		revrotb(stack, top, 'b');
	}
	else if ((*stack)[top] < (*stack)[top - 1] && (*stack)[top] >
	(*stack)[top - 2] && (*stack)[top - 1] > (*stack)[top - 2])
		swapb(stack, top, 'b');
	else if ((*stack)[top] > (*stack)[top - 1] && (*stack)[top] <
	(*stack)[top - 2] && (*stack)[top - 1] < (*stack)[top - 2])
		revrotb(stack, top, 'b');
}

void	malloc_size(int argc, char **argv, t_tops *top)
{
	char	**argenv;
	int		len;

	top->a = -1;
	top->b = -1;
	if (argv[1])
		argenv = ft_split(argv[1], ' ');
	len = lenarg(argenv);
	if (len >= 2 && argc == 2)
		top->malsize = len;
	else if (argc > 2 && len == 1)
		top->malsize = argc - 1;
	else
	{
		top->malsize = 0;
		checker(&len, top, argenv[0]);
	}
	ft_freee(argenv);
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
	if (top.malsize == 3)
		smallsorta(&stk.stack_a, 'a', 2);
	else
		quicksort_a(&stk, &top, (top.a + 1));
	freeab(stk.stack_a, stk.stack_b);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	while (1)
// 	{
// 		main2(argc, argv);
// 		system("leaks push_swap");
// 		scanf("x");
// 	}
// }