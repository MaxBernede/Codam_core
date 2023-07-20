/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frees.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:55:14 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/20 15:41:20 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_rule *rules)
{
	int	i;

	i = -1;
	if (!rules->m_nb)
		return ;
	pthread_mutex_destroy(&rules->m_stop_loop);
	--rules->m_nb;
	while (++i < rules->arg->phi_nb)
	{
		if (!rules->m_nb)
			return ;
		pthread_mutex_destroy(&rules->forks[i]);
		if (!rules->m_nb)
			return ;
		pthread_mutex_destroy(&rules->m_alive[i]);
	}
}

void	destroy(t_rule *rules, t_philo_thread *phi)
{
	if (rules->threads)
		free(rules->threads);
	if (rules->philos)
		free(rules->philos);
	if (rules->forks)
		free(rules->forks);
	if (phi)
		free(phi);
	destroy_mutexes(rules);
}
