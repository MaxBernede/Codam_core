/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:05:51 by jmeruma           #+#    #+#             */
/*   Updated: 2023/08/04 15:38:11 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin_free(char *s1, char const *s2)
{
	int		total;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s2 && s1)
	{
		ptr = ft_strdup(s1);
		return (free(s1), ptr);
	}
	total = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(total + 1);
	if (!ptr)
		return (free(s1), NULL);
	ft_strlcpy(ptr, (char *)s1, (ft_strlen(s1) + 1));
	ft_strlcat(ptr, (char *)s2, (total + 1));
	ptr[total] = '\0';
	free(s1);
	return (ptr);
}
