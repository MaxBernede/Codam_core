/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:59:34 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/19 16:27:28 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fill(t_rule *rules, char **argv, t_args *arg)
{
	int	error;

	error = 0;
	error += ft_atoi_overflow(argv[1], &arg->phi_nb);
	arg->t_to_die = ft_atoll(argv[2]);
	arg->t_to_eat = ft_atoll(argv[3]);
	arg->t_to_sleep = ft_atoll(argv[4]);
	if (arg->t_to_sleep > 2147483647 || arg->t_to_eat > 2147483647 || \
	arg->t_to_die > 2147483647)
		++error;
	if (argv[5])
		error += ft_atoi_overflow(argv[5], &arg->eat_max);
	else
		arg->eat_max = -1;
	rules->arg = arg;
	return (error);
}

void	fill_philos(t_rule *rules)
{
	int	i;

	i = 0;
	while (i < rules->arg->phi_nb)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].meals = rules->arg->eat_max;
		rules->philos[i].alive = true;
		rules->philos[i].m_alive = &rules->m_alive[i];
		if (i == 0)
		{
			rules->philos[i].l_fork = &rules->forks[rules->arg->phi_nb - 1];
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
	while (i < rules->arg->phi_nb)
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
	rules->m_alive = NULL;
	phi = NULL;
	rules->kill_loop = 0;
}
