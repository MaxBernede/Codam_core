/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoll.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 18:17:37 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/19 14:32:19 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *nb)
{
	int			i;
	int			x;
	long long	numb;

	i = 0;
	x = 1;
	numb = 0;
	while (nb[i] == ' ' || nb[i] == '\f' || nb[i] == '\n'
		|| nb[i] == '\r' || nb[i] == '\t' || nb[i] == '\v')
		i++;
	if (nb[i] == '-')
		x = -1;
	if (nb[i] == '+' || nb[i] == '-')
		i++;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		numb += nb[i] - '0';
		if (nb[i + 1] >= '0' && nb[i + 1] <= '9')
			numb *= 10;
		i++;
	}
	numb *= x;
	return (numb);
}
