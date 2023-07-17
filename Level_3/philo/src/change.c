/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 18:22:14 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/17 17:33:57 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_eat_nb(t_philo_thread *phi)
{
	pthread_mutex_lock(phi->philo->m_eat);
	phi->philo->meals_eaten += 1;
	pthread_mutex_unlock(phi->philo->m_eat);
}

void	change_t_died(t_philo_thread *phi)
{
	pthread_mutex_lock(phi->philo->m_died);
	phi->philo->time_die = current_time() + phi->arg->t_to_die;
	pthread_mutex_unlock(phi->philo->m_died);
}

void	change_end(t_philo *philo)
{
	pthread_mutex_lock(philo->m_eat);
	philo->end = true;
	pthread_mutex_unlock(philo->m_eat);
}

void	change_all_end(t_rule	*rules)
{
	int	i;

	i = 0;
	while (i < rules->arg->philo_nb)
	{
		change_end(&rules->philos[i]);
		++i;
	}
}
