/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxb <maxb@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:57:35 by mbernede      #+#    #+#                 */
/*   Updated: 2023/12/02 17:29:59 by maxb          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *phi, char *msg, int check)
{
	long long	time;

	time = philo_time_lived(phi);
	pthread_mutex_lock(phi->m_alive);
	if (check && !check_t_alive_deadlock(phi))
	{
		pthread_mutex_unlock(phi->m_alive);
		return ;
	}
	printf("%lld %d %s", time, phi->id, msg);
	pthread_mutex_unlock(phi->m_alive);
}

void	start_sleep(t_philo_thread *phi)

{
	print_msg(phi->philo, V_SLEEP, 1);
	if (mini_sleep(phi->arg->t_to_sleep, phi))
		return ;
	print_msg(phi->philo, V_THINK, 1);
}

void	try_eat(t_philo_thread *phi)
{
	pthread_mutex_lock(phi->philo->l_fork);
	print_msg(phi->philo, V_TAKE_FORK, 1);
	pthread_mutex_lock(phi->philo->r_fork);
	print_msg(phi->philo, V_TAKE_FORK, 1);
	print_msg(phi->philo, V_EAT, 1);
	if (mini_sleep(phi->arg->t_to_eat, phi))
	{
		pthread_mutex_unlock(phi->philo->l_fork);
		pthread_mutex_unlock(phi->philo->r_fork);
		return ;
	}
	pthread_mutex_unlock(phi->philo->l_fork);
	pthread_mutex_unlock(phi->philo->r_fork);
	change_t_died(phi);
}
