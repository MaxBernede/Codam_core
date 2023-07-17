/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotas.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 17:38:32 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/02/02 20:54:30 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../pushswap.h"
#include <stdio.h>

int	rota(int **stack, int top, char c)
{
	int	last;
	int	i;

	i = top;
	if (top <= 0)
		return (0);
	last = (*stack)[top];
	while (i)
	{
		(*stack)[i] = (*stack)[i - 1];
		--i;
	}
	(*stack)[i] = last;
	if (c == 'a')
		write(1, "ra\n", 3);
	return (1);
}

int	rotb(int **stack, int top, char c)
{
	int	last;
	int	i;

	i = top;
	if (top <= 0)
		return (0);
	last = (*stack)[top];
	while (i)
	{
		(*stack)[i] = (*stack)[i - 1];
		--i;
	}
	(*stack)[i] = last;
	if (c == 'b')
		write(1, "rb\n", 3);
	return (1);
}

int	rotabs(int **stack_a, int **stack_b, t_tops *top, char e)
{
	if (!rota(stack_a, top->a, 'c'))
		return (0);
	if (!rotb(stack_b, top->b, 'c'))
		return (0);
	if (e == 'r')
		write(1, "rr\n", 3);
	return (1);
}
