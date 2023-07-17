/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:14:27 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:58:13 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	c;

	c = 0;
	while (src[c])
		++c;
	if (size <= 0)
		return (c);
	x = 0;
	while (x < size - 1 && src[x])
	{
		dst[x] = src[x];
		++x;
	}
	dst[x] = 0;
	return (c);
}
