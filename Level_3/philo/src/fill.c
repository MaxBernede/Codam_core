/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:59:34 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/17 17:58:43 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fill(t_rule *rules, char **argv, t_args *arg)
{
	arg->philo_nb = ft_atoi(argv[1]);
	arg->t_to_die = ft_atoll(argv[2]);
	arg->t_to_eat = ft_atoll(argv[3]);
	arg->t_to_sleep = ft_atoll(argv[4]);
	if (argv[5])
		arg->eat_max = ft_atoi(argv[5]);
	else
		arg->eat_max = -1;
	rules->arg = arg;
}

void	fill_philos(t_rule *rules)
{
	int	i;

	i = 0;
	while (i < rules->arg->philo_nb)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].meals_eaten = 0;
		rules->philos[i].m_died = &rules->m_died[i];
		rules->philos[i].m_eat = &rules->m_eat[i];
		rules->philos[i].m_end = &rules->m_end[i];
		rules->philos[i].end = false;
		if (i == 0)
		{
			rules->philos[i].l_fork = &rules->forks[rules->arg->philo_nb - 1];
			rules->philos[i].r_fork = &rules->forks[i];
		}
		else
		{
			rules->philos[i].l_fork = &rules->forks[i - 1];
			rules->philos[i].r_fork = &rules->forks[i];
		}
		++i;
	}
}

void	fill_philo_solo(t_rule *rules, t_philo_thread *phi)
{
	int	i;

	i = 0;
	while (i < rules->arg->philo_nb)
	{
		phi[i].philo = &rules->philos[i];
		phi[i].arg = rules->arg;
		++i;
	}
}

void	fill_to_null(t_rule *rules, t_philo_thread *phi)
{
	rules->threads = NULL;
	rules->philos = NULL;
	rules->forks = NULL;
	rules->m_died = NULL;
	rules->m_eat = NULL;
	rules->m_end = NULL;
	phi = NULL;
}
