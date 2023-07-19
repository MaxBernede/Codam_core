/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frees.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:55:14 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/19 18:27:30 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_rule *rules)
{
	int	i;

	i = -1;
	while (++i < rules->arg->phi_nb)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(&rules->m_alive[i]);
	}
	pthread_mutex_destroy(&rules->m_stop_loop);
}

void	free_rule(t_rule *rules)
{
	free(rules->threads);
	free(rules->philos);
	free(rules->forks);
	free(rules->m_alive);
}

void	destroy_all(t_rule *rules, t_philo_thread *phi)
{
	destroy_mutexes(rules);
	free_rule(rules);
	if (phi)
		free(phi);
}

void	destroy(t_rule *rules, t_philo_thread *phi)
{
	if (rules->threads)
		free(rules->threads);
	if (rules->philos)
		free(rules->philos);
	if (rules->forks)
		free(rules->forks);
	destroy_mutexes(rules);
	if (phi)
		free(phi);
}
