/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logic.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:58:54 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/17 16:40:22 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_rule *rules)
{
	usleep(1000);
	while (1)
	{
		if (check_all_dead(rules))
		{
			change_all_end(rules);
			break ;
		}
		if (rules->arg->eat_max > 0 && check_all_eat(rules))
			break ;
		usleep(20);
	}
	return (0);
}
