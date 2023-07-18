/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoh.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 12:10:49 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/18 12:11:17 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

unsigned int	ft_atohex(const char *hex)
{
	int				i;
	unsigned int	numb;

	i = 0;
	numb = 0;
	while (hex[i] == ' ' || hex[i] == '\f' || hex[i] == '\n'
		|| hex[i] == '\r' || hex[i] == '\t' || hex[i] == '\v')
		i++;
	while (ft_isalnum(hex[i]) == 1 || hex[i] == '\n')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			numb += hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'z')
			numb += hex[i] - 'W';
		else if (hex[i] >= 'A' && hex[i] <= 'Z')
			numb += hex[i] - '7';
		if (ft_isalnum(hex[i + 1]) == 1)
			numb *= 16;
		i++;
	}
	return (numb);
}
