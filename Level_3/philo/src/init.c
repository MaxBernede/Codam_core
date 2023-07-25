/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:59:34 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/25 12:08:36 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_rule *rules)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&rules->m_stop_loop, NULL))
		return (1);
	++rules->m_nb;
	while (i < rules->arg->phi_nb)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (1);
		++rules->m_nb;
		if (pthread_mutex_init(&rules->m_alive[i], NULL))
			return (1);
		++rules->m_nb;
		++i;
	}
	return (0);
}

int	init_threads(t_rule *rules, t_philo_thread *phi)
{
	int	i;

	i = -1;
	while (++i < rules->arg->phi_nb)
	{
		if (pthread_create(&rules->threads[i], NULL, &routine, &phi[i]))
			return (1);
	}
	return (0);
}

int	alloc_mutexes(t_rule *rules)
{
	rules->forks = malloc (sizeof(pthread_mutex_t) * rules->arg->phi_nb);
	if (!rules->forks)
		return (1);
	rules->m_alive = malloc (sizeof(pthread_mutex_t) * rules->arg->phi_nb);
	if (!rules->m_alive)
		return (1);
	return (0);
}

int	init_all(t_rule *rules, t_philo_thread **phi)
{
	fill_to_null(rules, *phi);
	rules->threads = malloc (sizeof(pthread_t) * rules->arg->phi_nb);
	if (!rules->threads)
		return (1);
	rules->philos = malloc (sizeof(t_philo) * rules->arg->phi_nb);
	if (!rules->philos)
		return (1);
	*phi = malloc(sizeof(t_philo_thread) * rules->arg->phi_nb);
	if (!phi)
		return (1);
	if (alloc_mutexes(rules))
		return (1);
	if (init_mutex(rules))
		return (1);
	fill_philos(rules);
	fill_philo_solo(rules, *phi);
	return (0);
}
