/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:49:26 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:58:04 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ld;
	size_t	ls;
	size_t	y;

	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	y = 0;
	if (size > 0 && ld < size - 1)
	{
		while (y + ld < size - 1 && src[y])
		{
			dst[ld + y] = src[y];
			++y;
		}
		dst[ld + y] = 0;
	}
	if (ld >= size)
		ld = size;
	return (ls + ld);
}
