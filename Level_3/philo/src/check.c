/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:54:03 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/19 19:01:28 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_alive(t_philo philo)
{
	pthread_mutex_lock(philo.m_alive);
	if (philo.alive == false)
	{
		pthread_mutex_unlock(philo.m_alive);
		return (0);
	}
	pthread_mutex_unlock(philo.m_alive);
	return (1);
}

int	check_t_alive(t_philo philo)
{
	pthread_mutex_lock(philo.m_alive);
	if (philo.alive == false || current_time() >= philo.t_die)
	{
		pthread_mutex_unlock(philo.m_alive);
		return (0);
	}
	pthread_mutex_unlock(philo.m_alive);
	return (1);
}

int	check_t_alive_deadlock(t_philo philo)
{
	if (philo.alive == false || current_time() >= philo.t_die)
		return (0);
	return (1);
}

// i changed it to check first the dead ones
int	check_all_dead(t_rule *rules)
{
	int	i;

	i = -1;
	while (++i < rules->arg->phi_nb)
	{
		if (!check_alive(rules->philos[i]))
		{
			change_all_end(rules);
			print_msg(rules->philos[i], V_DIED, 0);
			return (1);
		}
	}
	i = -1;
	while (++i < rules->arg->phi_nb)
	{
		if (!check_t_alive(rules->philos[i]))
		{
			change_all_end(rules);
			print_msg(rules->philos[i], V_DIED, 0);
			return (1);
		}
	}
	return (0);
}
