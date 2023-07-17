/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_number.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:55:21 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/17 16:50:20 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[0] && str[0] == '-')
		return (1);
	if (str[0] && str[0] == '+')
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		++i;
	}
	if (i == 1 && str[0] == '+')
		return (1);
	return (0);
}
