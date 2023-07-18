/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:57:35 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/18 17:49:24 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo phi, int msg, int check)
{
	long long	time;

	time = philo_time_lived(phi);
	if (check && !check_alive(phi))
		return ;
	if (msg == V_TAKE_FORK)
		printf("%lld %d has taken a fork\n", time, phi.id);
	else if (msg == V_EAT)
		printf("%lld %d is eating\n", time, phi.id);
	else if (msg == V_THINK)
		printf("%lld %d is thinking\n", time, phi.id);
	else if (msg == V_SLEEP)
		printf("%lld %d is sleeping\n", time, phi.id);
	else
		printf("%lld %d died\n", time, phi.id);
}

void	start_sleep(t_philo_thread *phi)
{
	print_msg(*phi->philo, V_SLEEP, 1);
	mini_sleep(phi->arg->t_to_sleep, phi);
	print_msg(*phi->philo, V_THINK, 1);
}

void	try_eat(t_philo_thread *phi)
{
	pthread_mutex_lock(phi->philo->l_fork);
	print_msg(*phi->philo, V_TAKE_FORK, 1);
	pthread_mutex_lock(phi->philo->r_fork);
	print_msg(*phi->philo, V_TAKE_FORK, 1);
	print_msg(*phi->philo, V_EAT, 1);
	mini_sleep(phi->arg->t_to_eat, phi);
	pthread_mutex_unlock(phi->philo->l_fork);
	pthread_mutex_unlock(phi->philo->r_fork);
	change_t_died(phi);
	change_eat_nb(phi);
}
