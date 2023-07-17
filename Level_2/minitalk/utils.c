/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/05 14:49:58 by mbernede      #+#    #+#                 */
/*   Updated: 2023/03/06 16:24:27 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"
#include <limits.h>

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_atoi_overflow(char *str, int *number)
{
	int	i;
	int	neg;

	*number = 0;
	i = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		*number = (*number * 10) + (str[i] - 48);
		++i;
		if (*number < 0 && (*number != INT_MIN || neg == 1))
			return (1);
	}
	*number *= neg;
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	temp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	temp = n % 10 + 48;
	write(fd, &temp, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		++i;
	}
}
