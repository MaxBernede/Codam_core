/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:57:21 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/19 15:53:56 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(t_philo_thread *phi)
{
	pthread_mutex_lock(phi->philo->l_fork);
	print_msg(*phi->philo, V_TAKE_FORK, 1);
	mini_sleep(phi->arg->t_to_die, phi);
	pthread_mutex_unlock(phi->philo->l_fork);
	print_msg(*phi->philo, V_DIED, 0);
	return ((void *)phi);
}

void	*routine(void *arg)
{
	t_philo_thread	*phi;

	phi = (t_philo_thread *)arg;
	phi->philo->t_start = current_time();
	change_t_died(phi);
	if (phi->arg->phi_nb == 1)
		return (one_philo(phi));
	if (phi->philo->id % 2 == 1)
	{
		print_msg(*phi->philo, V_THINK, 1);
		mini_sleep(phi->arg->t_to_eat, phi);
	}
	while (phi->philo->meals)
	{
		if (!check_alive(*phi->philo))
			break ;
		try_eat(phi);
		--phi->philo->meals;
		start_sleep(phi);
	}
	return ((void *)phi);
}
