/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_2dfree.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 12:10:43 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/18 12:10:57 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_2dfree(char **p_arr)
{
	int	i;

	i = 0;
	while (p_arr[i] != NULL)
	{
		free(p_arr[i]);
		i++;
	}
	free(p_arr);
}
