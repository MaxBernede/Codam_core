/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:11:43 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:56:18 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	x;

	x = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (len--)
	{
		if (*ptr == x)
			return ((void *)ptr);
		++ptr;
	}
	return ((void *)0);
}
