/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:00:55 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/11 12:17:24 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	checks(unsigned long nb)
{
	if (nb == 0)
		return (1);
	return (0);
}

static char	*strcreation(unsigned long nb, int base)
{
	int		len;
	char	*ptr;

	len = 0;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	len++;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_basetoa(const char *baseset, int base, unsigned long nb)
{
	int		i;
	int		set;
	char	*ptr;

	i = 0;
	if (checks(nb) == 1)
	{
		ptr = ft_strdup("0");
		return (ptr);
	}
	ptr = strcreation(nb, base);
	if (!ptr)
		return (NULL);
	while (nb != 0)
	{
		set = nb % base;
		ptr[i] = baseset[set];
		nb /= base;
		i++;
	}
	return (ptr);
}
