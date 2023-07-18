/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logic.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:58:54 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/18 19:13:03 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mut(t_rule *rules)
{
	if (pthread_mutex_init(&rules->stop_die, NULL))
		return (1);
	if (pthread_mutex_init(&rules->stop_eat, NULL))
		return (1);
	return (0);
}

void	change_mutex(t_rule *rules, int choice)
{
	if (choice == 1)
	{
		pthread_mutex_lock(&rules->stop_die);
		rules->end = 1;
		pthread_mutex_unlock(&rules->stop_die);
	}
	else
	{
		pthread_mutex_lock(&rules->stop_eat);
		rules->end_loop = 1;
		pthread_mutex_unlock(&rules->stop_eat);
	}
}

int	no_data_race_please(t_rule *rules, int choice)
{
	if (choice == 1)
	{
		pthread_mutex_lock(&rules->stop_die);
		if (!rules->end)
		{
			pthread_mutex_unlock(&rules->stop_die);
			return (0);
		}
		pthread_mutex_unlock(&rules->stop_die);
		return (1);
	}
	else
	{
		pthread_mutex_lock(&rules->stop_eat);
		if (!rules->end_loop)
		{
			pthread_mutex_unlock(&rules->stop_eat);
			return (0);
		}
		pthread_mutex_unlock(&rules->stop_eat);
		return (1);
	}
}

void *loop_dead(void *arg)
{
	t_rule *rules;

	rules = (t_rule *)arg;
	while (no_data_race_please(rules, 1))
	{
		if (check_all_dead(rules))
			break ;
	}
	change_mutex(rules, 1);
	return ((void *)arg);
}

int	start(t_rule *rules)
{
	pthread_t die;

	usleep(1000);
	if (pthread_create(&die, NULL, &loop_dead, (void *)rules))
		return (1);
	while (no_data_race_please(rules, 2))
	{
		if (rules->arg->eat_max > 0 && check_all_eat(rules))
		{
			printf("HERE\n");
			change_all_end(rules);
			break ;
		}
	}
	change_mutex(rules, 2);
	if (pthread_join(die, NULL))
		return (ft_putstr_fd(ERR, 2), 1);
	return (0);
}
