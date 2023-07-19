/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 18:22:14 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/19 15:25:54 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_t_died(t_philo_thread *phi)
{
	pthread_mutex_lock(phi->philo->m_alive);
	phi->philo->t_die = current_time() + phi->arg->t_to_die;
	pthread_mutex_unlock(phi->philo->m_alive);
}

void	change_end(t_philo *philo)
{
	pthread_mutex_lock(philo->m_alive);
	philo->alive = false;
	pthread_mutex_unlock(philo->m_alive);
}

void	change_all_end(t_rule	*rules)
{
	int	i;

	i = -1;
	while (++i < rules->arg->phi_nb)
		change_end(&rules->philos[i]);
}
