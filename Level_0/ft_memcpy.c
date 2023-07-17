/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:43 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:56:31 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*srcc;
	unsigned char	*destt;

	if (dest == (void *)0 && src == (void *)0)
		return (0);
	srcc = (unsigned char *)src;
	destt = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		destt[i] = srcc[i];
		++i;
	}
	return (dest);
}
