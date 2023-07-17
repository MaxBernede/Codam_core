/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 22:46:53 by mbernede      #+#    #+#                 */
/*   Updated: 2023/03/07 15:09:07 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"
#include <stdio.h>

int	g_binary;

void	f_sig1(int sig)
{
	(void)sig;
	g_binary = 1;
}

int	message(int pid, char *str, int i, int b)
{
	while (str[i])
	{
		b = 8;
		while (b--)
		{
			if (str[i] >> b & 1)
			{
				if (kill(pid, SIGUSR1))
					return (ft_error());
			}
			else
			{
				if (kill(pid, SIGUSR2))
					return (ft_error());
			}
			while (!g_binary)
				;
			g_binary = 0;
		}
		++i;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	signal(SIGUSR1, f_sig1);
	if (argc != 3)
		return (ft_error());
	if (ft_atoi_overflow(argv[1], &pid))
		return (ft_error());
	g_binary = 0;
	if (message(pid, argv[2], 0, 8))
		return (0);
	message(pid, "\n", 0, 8);
	return (0);
}
