/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_2d_arrlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 12:10:39 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/18 12:10:59 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_2d_arrlen(char **p_arr)
{
	int	i;

	i = 0;
	while (p_arr[i] != NULL)
		i++;
	return (i);
}
