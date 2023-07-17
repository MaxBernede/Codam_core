/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:32:33 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:57:26 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countt(char const *s, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (s[i] && s)
	{
		while (s[i] == c)
			++i;
		if (s[i] != c && s[i] != 0)
			++wcount;
		while (s[i] != c && s[i] != 0)
			++i;
	}
	return (wcount);
}

static char	**ft_free(char **total)
{
	int	i;

	i = 0;
	while (total[i])
		free(total[i++]);
	free(total);
	return (0);
}

static char	**splitcopy(char	**total, char const *s, char c)
{
	int	i;
	int	index;
	int	start;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (s[i] == 0)
			break ;
		if (s[i] != c)
			start = i;
		while (s[i] != c && s[i] != 0)
			++i;
		total[index] = ft_substr(s, start, (i - start));
		if (!total[index])
			return (ft_free(total));
		++index;
	}
	return (total);
}

char	**ft_split(char const *s, char c)
{
	char	**total;
	int		wcount;

	if (!s)
		return (0);
	wcount = countt(s, c);
	total = (char **)ft_calloc(wcount + 1, sizeof(char *));
	if (!total)
		return (0);
	total = splitcopy(total, s, c);
	return (total);
}
