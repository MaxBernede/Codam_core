/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_overflow.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 12:11:21 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/20 15:44:40 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

void	first_half(const char *str, int *i, int *sign)
{
	*i = 0;
	*sign = 1;
	while (str[*i] == ' ' || str[*i] == '\f' || str[*i] == '\n'
		|| str[*i] == '\r' || str[*i] == '\t' || str[*i] == '\v')
		(*i)++;
	if (str[*i] == '-')
		*sign = -1;
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	while (str[*i] && str[*i] == '0')
		(*i)++;
}

int	ft_atoll_overflow(const char *str, int *numb, long long *nb)
{
	int	i;
	int	sign;

	*numb = 0;
	first_half(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		*numb += str[i] - '0';
		if (*numb < 0 && (*numb != INT_MIN || sign == 1))
			return (1);
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			*numb *= 10;
		i++;
	}
	*numb *= sign;
	*nb = (long long)*numb;
	return (0);
}

int	ft_atoi_overflow(const char *str, int *numb)
{
	int	i;
	int	sign;

	*numb = 0;
	first_half(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		*numb += str[i] - '0';
		if (*numb < 0 && (*numb != INT_MIN || sign == 1))
			return (1);
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			*numb *= 10;
		i++;
	}
	*numb *= sign;
	return (0);
}
