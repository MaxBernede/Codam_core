/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   revrota.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 15:22:53 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/02/02 21:26:58 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../pushswap.h"

int	revrota(int **stack, int top, char c)
{
	int	first;
	int	i;

	i = 0;
	if (top <= 0)
		return (0);
	first = (*stack)[i];
	while (i < top)
	{
		(*stack)[i] = (*stack)[i + 1];
		++i;
	}
	(*stack)[i] = first;
	if (c == 'a')
		write(1, "rra\n", 4);
	return (1);
}

int	revrotb(int **stack, int top, char c)
{
	int	first;
	int	i;

	i = 0;
	if (top <= 0)
		return (0);
	first = (*stack)[i];
	while (i < top)
	{
		(*stack)[i] = (*stack)[i + 1];
		++i;
	}
	(*stack)[i] = first;
	if (c == 'b')
		write(1, "rrb\n", 4);
	return (1);
}

int	revrotabs(int **stack_a, int **stack_b, t_tops *top, char e)
{
	if (!revrota(stack_a, top->a, 'c'))
		return (0);
	if (!revrotb(stack_b, top->b, 'c'))
		return (0);
	if (e == 'r')
		write(1, "rrr\n", 4);
	return (1);
}
