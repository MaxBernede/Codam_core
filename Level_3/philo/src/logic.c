/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logic.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:58:54 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/18 17:56:35 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *loop_dead(void *arg)
{
	t_rule *rules;

	rules = (t_rule *)arg;
	while (!rules->end_loop)
	{
		if (check_all_dead(rules))
			break ;
	}
	rules->end = 1;
	return ((void *)arg);
}

int	start(t_rule *rules)
{
	pthread_t die;

	usleep(1000);
	if (pthread_create(&die, NULL, &loop_dead, (void *)rules))
		return (1);
	while (!rules->end)
	{
		if (rules->arg->eat_max > 0 && check_all_eat(rules))
		{
			printf("HERE\n");
			change_all_end(rules);
			rules->end_loop = 1;
			break ;
		}
	}
	if (pthread_join(die, NULL))
		return (ft_putstr_fd(ERR, 2), 1);
	return (0);
}
