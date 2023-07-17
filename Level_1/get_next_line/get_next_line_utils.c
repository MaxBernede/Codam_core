/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:53:28 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/19 17:55:33 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*returned(char *str)
{
	int		len;
	char	*ptr;
	int		i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = -1;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		free(str);
		return (NULL);
	}
	while (str[++i])
		ptr[i] = str[i];
	ptr[i] = 0;
	free(str);
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		++i;
	return (i);
}

char	*ft_memmove(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (n--)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}

char	*coppy(char *str, char *tempread, int i)
{
	int	n;
	int	len;

	n = 0;
	len = ft_strlen(str);
	if (tempread[i] == '\n' && tempread[i])
		++i;
	while (n < i)
	{
		str[len + n] = tempread[n];
		++n;
	}
	str[len + n] = 0;
	return (str);
}
