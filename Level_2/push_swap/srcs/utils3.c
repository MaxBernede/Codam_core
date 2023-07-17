/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 11:31:22 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/02 20:45:31 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pushback_a(t_stacks *stk, t_tops *top, int push)
{
	int	i;

	i = 0;
	while (i < push)
	{
		pusha(stk, top, 'a');
		++i;
	}
}

void	issmola(t_stacks *stk, char e, t_tops *top, int push)
{
	if (push == 3)
	{
		if (top->a == 2)
			smallsorta(&stk->stack_a, e, top->a);
		else
			smola(stk, e, top);
	}
}

void	issmolb(t_stacks *stk, char e, t_tops *top, int push)
{
	if (push == 3)
	{
		if (top->b == 2)
			smallsortb(&stk->stack_b, top->b);
		else
			smolb(stk, e, top);
	}
}

void	swap_from_a(t_stacks *stk, t_tops *top)
{
	if (stk->stack_b[top->b] < stk->stack_b[top->b - 1])
	{
		swaps(&stk->stack_a, &stk->stack_b, top, 's');
	}
	else
		swapa(&stk->stack_a, top->a, 'a');
}

void	swap_from_b(t_stacks *stk, t_tops *top)
{
	if (stk->stack_a[top->a] > stk->stack_a[top->a - 1])
	{
		swaps(&stk->stack_a, &stk->stack_b, top, 's');
	}
	else
		swapb(&stk->stack_b, top->b, 'b');
}
