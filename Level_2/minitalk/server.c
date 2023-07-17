/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 22:46:54 by mbernede      #+#    #+#                 */
/*   Updated: 2023/03/06 16:27:43 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./minitalk.h"

void	handle(int sig, siginfo_t *siginfo, void *context)
{
	static int				i;
	static unsigned char	c;

	(void)context;
	i++;
	if (i < 8)
	{
		c <<= 1;
		c += sig == SIGUSR1;
	}
	else
	{
		c <<= 1;
		c += sig == SIGUSR1;
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	write(1, "PID is ", 8);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle;
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
