/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:57:21 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/18 17:54:59 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(t_philo_thread *phi)
{
	pthread_mutex_lock(phi->philo->l_fork);
	print_msg(*phi->philo, V_TAKE_FORK, 1);
	mini_sleep(phi->arg->t_to_die, phi);
	pthread_mutex_unlock(phi->philo->l_fork);
	return ((void *)phi);
}

t_philo_thread	*philo_creator(t_rule *rules, int i, t_philo_thread *s_philo)
{
	s_philo->philo = &rules->philos[i];
	s_philo->arg = rules->arg;
	return (s_philo);
}

void	*routine(void *arg)
{
	t_philo_thread	*phi;

	phi = (t_philo_thread *)arg;
	phi->philo->start_time = current_time();
	change_t_died(phi);
	if (phi->arg->philo_nb == 1)
		return (one_philo(phi));
	if (phi->philo->id % 2 == 1)
	{
		print_msg(*phi->philo, V_THINK, 1);
		mini_sleep(phi->arg->t_to_eat, phi);
	}
	while (1)
	{
		if (phi->philo->meals_eaten == phi->arg->eat_max)
			break ;
		if (!check_alive(*phi->philo))
			break ;
		try_eat(phi);
		start_sleep(phi);
	}
	return ((void *)phi);
}
