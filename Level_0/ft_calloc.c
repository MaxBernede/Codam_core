/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:59:30 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:55:13 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	c;
	size_t	added;

	added = size * nmemb;
	ptr = malloc(added);
	if (!ptr)
		return (NULL);
	c = 0;
	while (c < added)
	{
		ptr[c] = '\0';
		++c;
	}
	return ((void *)ptr);
}
