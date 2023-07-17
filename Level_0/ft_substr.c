/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:58:14 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:59:04 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s) || !len)
		return (ft_strdup(""));
	if (ft_strlen(s) < (len + start))
		len = ft_strlen(s + start);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (len--)
	{
		ptr[i] = s[i + start];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}
