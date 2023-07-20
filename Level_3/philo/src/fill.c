/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:59:34 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/20 15:41:31 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fill(t_rule *rules, char **argv, t_args *arg)
{
	int	error;
	int	temp;

	error = 0;
	error += ft_atoi_overflow(argv[1], &arg->phi_nb);
	error += ft_atoll_overflow(argv[2], &temp, &arg->t_to_die);
	error += ft_atoll_overflow(argv[3], &temp, &arg->t_to_eat);
	error += ft_atoll_overflow(argv[4], &temp, &arg->t_to_sleep);
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
	rules->m_nb = 0;
}
