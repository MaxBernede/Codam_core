/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivottemp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:22:46 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/15 14:09:33 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../pushswap.h"

void	sort(int **arr, int max)
{
	int	i;
	int	nb;
	int	j;

	i = 1;
	while (i < max)
	{
		nb = (*arr)[i];
		j = i - 1;
		while (j >= 0 && (*arr)[j] < nb)
		{
			(*arr)[j + 1] = (*arr)[j];
			j = j - 1;
		}
		(*arr)[j + 1] = nb;
		++i;
	}
}

int	returnpivot(int *stack, int push, int top)
{
	int	*temp;
	int	pivot;
	int	i;

	i = -1;
	temp = malloc((push) * sizeof(int));
	if (!temp)
		return (0);
	while (++i < push)
		temp[i] = stack[top - push + i + 1];
	sort(&temp, push);
	pivot = temp[(push / 2)];
	free(temp);
	return (pivot);
}
