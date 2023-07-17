/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 16:58:21 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/17 18:20:38 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fun(void)
{
	system("leaks philo");
}

void	wait_all_threads(t_rule *rules)
{
	int	i;

	i = 0;
	while (i < rules->arg->philo_nb)
	{
		if (pthread_join(rules->threads[i], NULL))
		{
			printf("Failed to join thread nb : %d.\n", i);
			return ;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_rule			rules;
	t_args			arg;
	t_philo_thread	*phi;

	if (argc < 5 || argc > 6)
		return (ft_putstr_fd(ERR_ARG, 2), 1);
	if (check_input(argv))
		return (ft_putstr_fd(ERR, 2), 1);
	init_fill(&rules, argv, &arg);
	if (!arg.philo_nb)
		return (ft_putstr_fd(ERR, 2), 1);
	if (init_all(&rules, &phi))
	{
		destroy(&rules, phi);
		return (ft_putstr_fd(ERR, 2), 1);
	}
	start(&rules);
	wait_all_threads(&rules);
	destroy_all(&rules, phi);
	return (0);
}
