/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smolsort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/14 12:04:00 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/02/02 21:41:25 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	smola(t_stacks *stk, char e, t_tops *top)
{
	if (stk->stack_a[top->a] > stk->stack_a[top->a - 1] && \
	stk->stack_a[top->a] > stk->stack_a[top->a - 2] \
	&& stk->stack_a[top->a - 1] < stk->stack_a[top->a - 2])
	{
		swap_from_a(stk, top);
		rota(&stk->stack_a, top->a, e);
		swapa(&stk->stack_a, top->a, e);
		revrota(&stk->stack_a, top->a, e);
	}
	else if (stk->stack_a[top->a] > stk->stack_a[top->a - 1] \
	&& stk->stack_a[top->a] > stk->stack_a[top->a - 2] && \
	stk->stack_a[top->a - 1] > stk->stack_a[top->a - 2])
	{
		swap_from_a(stk, top);
		rota(&stk->stack_a, top->a, e);
		swapa(&stk->stack_a, top->a, e);
		revrota(&stk->stack_a, top->a, e);
		swapa(&stk->stack_a, top->a, e);
	}
	else
		endsmola(stk, e, top);
}

void	endsmola(t_stacks *stk, char e, t_tops *top)
{
	if (stk->stack_a[top->a] < stk->stack_a[top->a - 1] && \
	stk->stack_a[top->a] < stk->stack_a[top->a - 2] && \
	stk->stack_a[top->a - 1] > stk->stack_a[top->a - 2])
	{
		rota(&stk->stack_a, top->a, e);
		swap_from_a(stk, top);
		revrota(&stk->stack_a, top->a, e);
	}
	else if (stk->stack_a[top->a] > stk->stack_a[top->a - 1] && \
	stk->stack_a[top->a] < stk->stack_a[top->a - 2] && \
	stk->stack_a[top->a - 1] < stk->stack_a[top->a - 2])
		swap_from_a(stk, top);
	else if (stk->stack_a[top->a] < stk->stack_a[top->a - 1] && \
	stk->stack_a[top->a] > stk->stack_a[top->a - 2] && \
	stk->stack_a[top->a - 1] > stk->stack_a[top->a - 2])
	{
		rota(&stk->stack_a, top->a, e);
		swap_from_a(stk, top);
		revrota(&stk->stack_a, top->a, e);
		swapa(&stk->stack_a, top->a, e);
	}
}

void	smolb(t_stacks *stk, char e, t_tops *top)
{
	if (stk->stack_b[top->b] < stk->stack_b[top->b - 1] && \
	stk->stack_b[top->b] < stk->stack_b[top->b - 2] && \
	stk->stack_b[top->b - 1] > stk->stack_b[top->b - 2])
	{
		swap_from_b(stk, top);
		rotb(&stk->stack_b, top->b, e);
		swapb(&stk->stack_b, top->b, e);
		revrotb(&stk->stack_b, top->b, e);
	}
	else if (stk->stack_b[top->b] < stk->stack_b[top->b - 1] && \
	stk->stack_b[top->b] < stk->stack_b[top->b - 2] && \
	stk->stack_b[top->b - 1] < stk->stack_b[top->b - 2])
	{
		swap_from_b(stk, top);
		rotb(&stk->stack_b, top->b, e);
		swapb(&stk->stack_b, top->b, e);
		revrotb(&stk->stack_b, top->b, e);
		swapb(&stk->stack_b, top->b, e);
	}
	else
		endsmolb(stk, e, top);
}

void	endsmolb(t_stacks *stk, char e, t_tops *top)
{
	if (stk->stack_b[top->b] > stk->stack_b[top->b - 1] && \
	stk->stack_b[top->b] > stk->stack_b[top->b - 2] && \
	stk->stack_b[top->b - 1] < stk->stack_b[top->b - 2])
	{
		rotb(&stk->stack_b, top->b, e);
		swap_from_b(stk, top);
		revrotb(&stk->stack_b, top->b, e);
	}
	else if (stk->stack_b[top->b] < stk->stack_b[top->b - 1] && \
	stk->stack_b[top->b] > stk->stack_b[top->b - 2] && \
	stk->stack_b[top->b - 1] > stk->stack_b[top->b - 2])
		swap_from_b(stk, top);
	else if (stk->stack_b[top->b] > stk->stack_b[top->b - 1] && \
	stk->stack_b[top->b] < stk->stack_b[top->b - 2] && \
	stk->stack_b[top->b - 1] < stk->stack_b[top->b - 2])
	{
		rotb(&stk->stack_b, top->b, e);
		swap_from_b(stk, top);
		revrotb(&stk->stack_b, top->b, e);
		swapb(&stk->stack_b, top->b, e);
	}
}
