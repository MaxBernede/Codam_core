/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frees.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:55:14 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/17 18:10:20 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_rule *rules)
{
	int	i;

	i = -1;
	while (++i < rules->arg->philo_nb)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(&rules->m_died[i]);
		pthread_mutex_destroy(&rules->m_eat[i]);
		pthread_mutex_destroy(&rules->m_end[i]);
	}
}

void	free_rule(t_rule *rules)
{
	free(rules->threads);
	free(rules->philos);
	free(rules->forks);
	free(rules->m_died);
	free(rules->m_eat);
	free(rules->m_end);
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
	if (rules->m_died)
		free(rules->m_died);
	if (rules->m_eat)
		free(rules->m_eat);
	if (rules->m_end)
		free(rules->m_end);
	if (phi)
		free(phi);
}
