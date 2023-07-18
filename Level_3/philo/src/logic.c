/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logic.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:58:54 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/18 12:24:15 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_rule *rules)
{
	usleep(500);
	while (1)
	{
		if (check_all_dead(rules))
		{
			change_all_end(rules);
			break ;
		}
		if (rules->arg->eat_max > 0 && check_all_eat(rules))
			break ;
	}
	return (0);
}
