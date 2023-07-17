/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/29 14:03:57 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/05 12:07:04 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "../pushswap.h"
#include "../libft/libft.h"

int	lenarg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		++i;
	return (i);
}

int	check_input(char *toadd)
{
	int	i;

	i = 0;
	if (!toadd)
		return (0);
	if (toadd && toadd[i] == '-')
		++i;
	if ((!toadd[i] && i == 1) || (!i && !toadd[i]))
		return (0);
	while (toadd[i])
	{
		if (toadd[i] < 48 || toadd[i] > 57)
			return (0);
		++i;
	}
	return (1);
}

int	ft_atoi_overflow(char *str, int *number)
{
	int	i;
	int	neg;

	*number = 0;
	i = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		*number = (*number * 10) + (str[i] - 48);
		++i;
		if (*number < 0 && (*number != INT_MIN || neg == 1))
			return (1);
	}
	*number *= neg;
	return (0);
}

int	freeab(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
	return (0);
}

void	ft_freee(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}
