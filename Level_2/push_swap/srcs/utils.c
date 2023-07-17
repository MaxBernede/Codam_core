/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 17:06:34 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/01/29 23:44:57 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../pushswap.h"
#include "../libft/libft.h"

void	backb(int **stack, int top, int itenb, int pushn)
{
	if ((top - itenb - pushn) < itenb - pushn)
	{
		while ((top - pushn - itenb) > 0)
		{
			rotb(stack, top, 'b');
			++itenb;
		}	
	}
	else
	{
		while ((itenb - pushn))
		{
			revrotb(stack, top, 'b');
			--itenb;
		}
	}
}

void	backa(int **stack, int top, int itenb, int pushn)
{
	if ((top - itenb - pushn) < itenb - pushn)
	{
		while ((top - pushn - itenb) > 0)
		{
			rota(stack, top, 'a');
			++itenb;
		}	
	}
	else
	{
		while ((itenb - pushn))
		{
			revrota(stack, top, 'a');
			--itenb;
		}
	}
}

int	checker(int *stack, t_tops *top, char *toadd)
{
	int	i;
	int	nb;

	if (!check_input(toadd))
		return (0);
	i = 0;
	if (ft_atoi_overflow(toadd, &nb))
		return (0);
	while (i < top->a)
	{
		if (stack[i] == nb)
			return (0);
		++i;
	}
	return (1);
}

void	argorstr(int argc, char **argv, t_tops *top, int **stack_a)
{
	char	**argenv;
	int		len;

	argenv = ft_split(argv[1], ' ');
	len = lenarg(argenv);
	if (len >= 2 && argc == 2)
		stackcrea(top->malsize + 1, argenv - 1, top, stack_a);
	else
		stackcrea(argc, argv, top, stack_a);
	ft_freee(argenv);
}

void	stackcrea(int argc, char **argv, t_tops *top, int **stack_a)
{
	while (argc > 1)
	{
		top->a += 1;
		--argc;
		if (!checker(*stack_a, top, argv[argc]))
		{
			write(2, "Error\n", 6);
			top->malsize = 0;
			return ;
		}
		(*stack_a)[top->a] = ft_atoi(argv[argc]);
	}
}
