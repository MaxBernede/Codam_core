/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:56:59 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/17 16:48:14 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	philo_time_lived(t_philo phi)
{
	return (current_time() - phi.start_time);
}

void	mini_sleep(int time, t_philo_thread *phi)
{
	long long	start;

	if (!time)
		return ;
	start = current_time();
	while (current_time() < (start + time))
	{
		if (!check_alive(*phi->philo))
			break ;
		usleep(250);
	}
}
