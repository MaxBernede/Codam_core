/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:10:18 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:56:44 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*srcc;
	unsigned char	*destt;

	if (dest == (void *)0 && src == (void *)0)
		return (0);
	srcc = (unsigned char *) src;
	destt = (unsigned char *) dest;
	if (dest < src)
	{
		while (n--)
			*destt++ = *srcc++;
	}
	else
	{
		srcc += n - 1;
		destt += n - 1;
		while (n--)
			*destt-- = *srcc--;
	}
	return (dest);
}
