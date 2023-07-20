/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 15:15:25 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/20 15:14:48 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_number(argv[i]))
			return (1);
		++i;
	}
	return (0);
}
