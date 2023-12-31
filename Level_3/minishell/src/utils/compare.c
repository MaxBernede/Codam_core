/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compare.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:11:41 by mbernede      #+#    #+#                 */
/*   Updated: 2023/08/31 13:11:42 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (ft_toupper(s1[i]) == ft_toupper(s2[i]))
			++i;
		else
			return (-1);
	}
	if (s1[i] == s2[i])
		return (0);
	else
		return (-1);
}
