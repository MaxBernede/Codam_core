/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:06:21 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/09 19:47:47 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
			++i;
		else
			break ;
	}
	if (s1[i] == '\0' && s1[i] != s2[i])
		return (-1);
	if (s2[i] == '\0' && s1[i] != s2[i])
		return (1);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
