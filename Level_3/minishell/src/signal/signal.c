
#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#define CHILD 0

extern int	g_signal;

void	f_sigmain(int sig)
{
	ft_printf("\n");
	g_signal = 130;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	mainsignal(int mode)
{
	if (mode == 0)
	{
		signal(SIGINT, f_sigmain);
		signal(SIGQUIT, SIG_IGN);
	}
	if (mode == 1)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	if (mode == 2)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
	}
	if (mode == 3)
	{
		signal(SIGINT, f_sigmain);
		signal(SIGQUIT, SIG_DFL);
	}
}
