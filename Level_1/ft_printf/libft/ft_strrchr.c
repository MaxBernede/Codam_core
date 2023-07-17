/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:25:56 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:58:47 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*temp;

	ptr = (char *)s;
	temp = 0;
	while (*ptr)
	{
		if (*ptr == (char)c)
			temp = ptr;
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (temp);
}
