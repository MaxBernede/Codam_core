/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:59:34 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/18 13:05:31 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_rule *rules)
{
	int	i;

	i = 0;
	while (i < rules->arg->philo_nb)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (1);
		if (pthread_mutex_init(&rules->m_died[i], NULL))
			return (1);
		if (pthread_mutex_init(&rules->m_eat[i], NULL))
			return (1);
		if (pthread_mutex_init(&rules->m_end[i], NULL))
			return (1);
		++i;
	}
	return (0);
}

int	init_threads(t_rule *rules, t_philo_thread *philo_solo)
{
	int	i;

	i = 0;
	while (i < rules->arg->philo_nb)
	{
		if (pthread_create(&rules->threads[i], NULL, &routine, &philo_solo[i]))
			return (1);
		++i;
	}
	i = 0;
	return (0);
}

int	alloc_mutexes(t_rule *rules)
{
	rules->forks = malloc (sizeof(pthread_mutex_t) * rules->arg->philo_nb);
	if (!rules->forks)
		return (1);
	rules->m_died = malloc (sizeof(pthread_mutex_t) * rules->arg->philo_nb);
	if (!rules->m_died)
		return (1);
	rules->m_eat = malloc (sizeof(pthread_mutex_t) * rules->arg->philo_nb);
	if (!rules->m_eat)
		return (1);
	rules->m_end = malloc (sizeof(pthread_mutex_t) * rules->arg->philo_nb);
	if (!rules->m_end)
		return (1);
	return (0);
}

int	init_all(t_rule *rules, t_philo_thread **phi)
{
	fill_to_null(rules, *phi);
	rules->threads = malloc (sizeof(pthread_t) * rules->arg->philo_nb);
	if (!rules->threads)
		return (1);
	rules->philos = malloc (sizeof(t_philo) * rules->arg->philo_nb);
	if (!rules->philos)
		return (1);
	if (alloc_mutexes(rules))
		return (1);
	*phi = malloc(sizeof(t_philo_thread) * rules->arg->philo_nb);
	if (!phi)
		return (1);
	if (init_mutex(rules))
		return (1);
	fill_philos(rules);
	fill_philo_solo(rules, *phi);
	if (init_threads(rules, *phi))
		return (1);
	return (0);
}
