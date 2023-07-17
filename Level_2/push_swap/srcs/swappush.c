/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swappush.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 17:35:38 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/02/02 21:09:17 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../pushswap.h"

int	pusha(t_stacks *stk, t_tops *top, char e)
{
	if (top->b < 0)
		return (0);
	top->a += 1;
	stk->stack_a[top->a] = stk->stack_b[top->b];
	top->b -= 1;
	if (e == 'a')
		write(1, "pa\n", 3);
	return (1);
}

int	pushb(t_stacks *stk, t_tops *top, char e)
{
	if (top->a < 0)
		return (0);
	top->b += 1;
	stk->stack_b[top->b] = stk->stack_a[top->a];
	top->a -= 1;
	if (e == 'b')
		write(1, "pb\n", 3);
	return (1);
}

int	swapa(int **stack, int top, char c)
{
	int	temp;

	if (top <= 0)
		return (0);
	temp = (*stack)[top];
	(*stack)[top] = (*stack)[top - 1];
	(*stack)[top - 1] = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	return (1);
}

int	swapb(int **stack, int top, char c)
{
	int	temp;

	if (top <= 0)
		return (0);
	temp = (*stack)[top];
	(*stack)[top] = (*stack)[top - 1];
	(*stack)[top - 1] = temp;
	if (c == 'b')
		write(1, "sb\n", 3);
	return (1);
}

int	swaps(int **stack_a, int **stack_b, t_tops *top, char e)
{
	if (!swapa(stack_a, top->a, 'c'))
		return (0);
	if (!swapb(stack_b, top->b, 'c'))
		return (0);
	if (e == 's')
		write(1, "ss\n", 3);
	return (1);
}
