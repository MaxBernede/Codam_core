/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maxb <maxb@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:56:59 by mbernede      #+#    #+#                 */
/*   Updated: 2023/12/02 17:42:14 by maxb          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	philo_time_lived(t_philo *phi)
{
	return (current_time() - phi->t_start);
}

int	mini_sleep(int time, t_philo_thread *phi)
{
	long long	start;

	if (!time)
		return (1);
	start = current_time();
	while (current_time() < (start + time))
	{
		if (phi && !check_t_alive(phi->philo))
			return (1);
		usleep(300);
	}
	return (0);
}
