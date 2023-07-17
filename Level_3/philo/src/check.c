/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:54:03 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/17 15:15:11 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_alive(t_philo philo)
{
	pthread_mutex_lock(philo.m_end);
	if (philo.end == true)
	{
		pthread_mutex_unlock(philo.m_end);
		return (0);
	}
	pthread_mutex_unlock(philo.m_end);
	return (1);
}

int	check_died(t_philo	*philo)
{
	pthread_mutex_lock(philo->m_died);
	if (current_time() >= philo->time_die)
	{
		pthread_mutex_unlock(philo->m_died);
		return (1);
	}
	pthread_mutex_unlock(philo->m_died);
	return (0);
}

int	check_all_dead(t_rule *rules)
{
	int	i;

	i = 0;
	while (i < rules->arg->philo_nb)
	{
		if (check_died(&rules->philos[i]))
		{
			print_msg(rules->philos[i], V_DIED);
			return (1);
		}
		++i;
	}
	return (0);
}

int	check_eat(t_philo	philo, int eat_max)
{
	pthread_mutex_lock(philo.m_eat);
	if (philo.meals_eaten >= eat_max)
	{
		pthread_mutex_unlock(philo.m_eat);
		return (1);
	}
	pthread_mutex_unlock(philo.m_eat);
	return (0);
}

int	check_all_eat(t_rule *rules)
{
	int	i;

	i = 0;
	while (i < rules->arg->philo_nb)
	{
		if (check_eat(rules->philos[i], rules->arg->eat_max))
			return (1);
		++i;
	}
	return (0);
}
