/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frees.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:55:14 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/25 12:46:53 by mbernede      ########   odam.nl         */
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
		--rules->m_nb;
		if (!rules->m_nb)
			return ;
		--rules->m_nb;
	}
}

void	destroy(t_rule *rules, t_philo_thread *phi)
{
	destroy_mutexes(rules);
	if (rules->threads)
		free(rules->threads);
	if (rules->philos)
		free(rules->philos);
	if (rules->forks)
		free(rules->forks);
	if (rules->m_alive)
		free(rules->m_alive);
	if (phi)
		free(phi);
}
