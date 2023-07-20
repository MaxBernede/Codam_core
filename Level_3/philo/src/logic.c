/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logic.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:58:54 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/20 11:04:56 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_mutex(t_rule *rules)
{
	pthread_mutex_lock(&rules->m_stop_loop);
	rules->kill_loop = 1;
	pthread_mutex_unlock(&rules->m_stop_loop);
}

int	kill_loop(t_rule *rules)
{
	pthread_mutex_lock(&rules->m_stop_loop);
	if (rules->kill_loop)
	{
		pthread_mutex_unlock(&rules->m_stop_loop);
		return (1);
	}
	pthread_mutex_unlock(&rules->m_stop_loop);
	return (0);
}

void	*loop_dead(void *arg)
{
	t_rule	*rules;

	rules = (t_rule *)arg;
	while (!kill_loop(rules))
	{
		if (check_all_dead(rules))
			break ;
	}
	return ((void *)arg);
}

int	start(t_rule *rules)
{
	pthread_t	die;

	if (rules->arg->phi_nb == 1)
	{
		mini_sleep(rules->arg->t_to_die, NULL);
		return (0);
	}
	else
		mini_sleep(10, NULL);
	if (pthread_create(&die, NULL, &loop_dead, (void *)rules))
		return (1);
	wait_all_threads(rules);
	change_mutex(rules);
	if (pthread_join(die, NULL))
		return (ft_putstr_fd(ERR, 2), 1);
	return (0);
}
