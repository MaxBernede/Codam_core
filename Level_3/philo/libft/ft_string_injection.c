/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_injection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:07:29 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/24 16:46:18 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_string_injection(char *line, int index, char *str)
{
	char	*end;
	char	*first;
	int		line_len;
	char	*str_line;

	if (!line || !str)
		return (NULL);
	line_len = ft_strlen(line);
	if (index > line_len)
		return (NULL);
	first = ft_substr(line, 0, index);
	end = ft_substr(line, index, line_len - index);
	if (!first || !end)
		return (NULL);
	str_line = ft_strjoin_free(first, str);
	if (!line)
		return (NULL);
	str_line = ft_strjoin_free(str_line, end);
	free(end);
	return (str_line);
}
