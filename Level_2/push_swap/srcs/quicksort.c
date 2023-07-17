/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/10 17:42:38 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/02/02 20:46:06 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../pushswap.h"

int	ordered(t_stacks *stk, int push, char c, t_tops *top)
{
	int	i;

	i = 1;
	if (push <= 1)
		return (1);
	if ((push == 2) && (stk->stack_a[top->a - 1] < stk->stack_a[top->a]))
	{
		swap_from_a(stk, top);
		return (1);
	}
	while (i < push)
	{
		if (stk->stack_a[top->a - i] < stk->stack_a[top->a - i + 1])
			return (0);
		++i;
	}
	return (1);
}

int	orderedb(t_stacks *stk, int push, char c, t_tops *top)
{
	int	i;

	i = 1;
	if (push == 1)
		return (1);
	if ((push == 2) && (stk->stack_b[top->b - 1] > stk->stack_b[top->b]))
	{
		swap_from_b(stk, top);
		return (1);
	}
	while (i < push)
	{
		if (stk->stack_b[top->b - i] > stk->stack_b[top->b - i + 1])
			return (0);
		++i;
	}
	return (1);
}

int	push_from_b(t_stacks *stk, t_tops *top, int push_b, int check)
{
	if (push_b && check)
	{
		pushb(stk, top, 'b');
		swap_from_a(stk, top);
	}
	else
		pushb(stk, top, 'b');
	return (1);
}

void	quicksort_a(t_stacks *stk, t_tops *top, int push)
{
	int	push_b;
	int	pivot;
	int	i;
	int	itenb;

	i = push;
	itenb = 0;
	push_b = 0;
	issmola(stk, 'a', top, push);
	if (ordered(stk, push, 'a', top))
		return ;
	pivot = returnpivot(stk->stack_a, push, top->a);
	while (itenb < push)
	{
		if (stk->stack_a[top->a] < pivot)
		{
			itenb += pushb(stk, top, 'b');
			++push_b;
		}
		else
			itenb += rota(&stk->stack_a, top->a, 'a');
	}
	backa(&stk->stack_a, top->a, itenb, push_b);
	quicksort_a(stk, top, i - push_b);
	quicksort_b(stk, top, push_b);
}

void	quicksort_b(t_stacks *stk, t_tops *top, int push)
{
	int	pivot;
	int	i;
	int	push_a;
	int	itenb;

	i = push;
	itenb = 0;
	push_a = 0;
	issmolb(stk, 'b', top, push);
	if (orderedb(stk, push, 'b', top))
		return (pushback_a(stk, top, push));
	pivot = returnpivot(stk->stack_b, push, top->b);
	while (itenb < push)
	{
		if (stk->stack_b[top->b] > pivot)
		{
			itenb += pusha(stk, top, 'a');
			++push_a;
		}
		else
			itenb += rotb(&stk->stack_b, top->b, 'b');
	}
	backb(&stk->stack_b, top->b, itenb, push_a);
	quicksort_a(stk, top, push_a);
	quicksort_b(stk, top, i - push_a);
}
