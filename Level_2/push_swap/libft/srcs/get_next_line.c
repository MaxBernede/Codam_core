/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:40:53 by mbernede          #+#    #+#             */
/*   Updated: 2022/12/18 22:39:12 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

char	*reading(int fd, int *red, int i)
{
	static char	buf[BUFFER_SIZE + 1];

	while (1)
	{
		if (!*buf)
		{
			*red = read(fd, buf, BUFFER_SIZE);
			if (*red < 0)
				return (NULL);
			buf[*red] = 0;
			return (buf);
		}
		while (buf[++i])
		{
			if (buf[i] == '\n')
			{
				ft_memmovegnl(&buf[0], &buf[i + 1], BUFFER_SIZE - i - 1);
				i = -1;
				if (buf[0] != 0)
					return (buf);
			}
		}
		*buf = 0;
	}
	return (buf);
}

char	*ft_strdupgnl(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i])
		++i;
	ptr = (char *)malloc(i + 1 + BUFFER_SIZE);
	if (!ptr)
		return (free(str), NULL);
	i = -1;
	while (str[++i])
		ptr[i] = str[i];
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

char	*memalloc(char *str, int i, char *tempread)
{
	if (!str)
	{
		if (tempread[i] == '\n')
			++i;
		str = malloc(sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
		str[0] = 0;
	}
	else if (str && *tempread)
		str = ft_strdupgnl(str);
	return (str);
}

char	*brexit(char *str, int red, int *i)
{
	int			len;
	static int	out;

	len = ft_strlengnl(str);
	if (len != 0)
	{
		if (str[len - 1] == '\n')
			*i = 0;
	}
	else if (red == BUFFER_SIZE)
		*i = 1;
	else if (out)
	{
		str = NULL;
		*i = 0;
	}
	else if (str)
	{
		out = 1;
		*i = 0;
	}
	else
		*i = 1;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*tempread;
	char		*str;
	static int	red;
	int			i;

	str = NULL;
	while (1)
	{
		i = 0;
		tempread = reading(fd, &red, -1);
		if (red < 0 || (!*tempread && !str))
			return (free(str), NULL);
		while (tempread[i] != '\n' && tempread[i])
			++i;
		str = memalloc(str, i, tempread);
		if (!str)
			return (NULL);
		str = coppygnl(str, tempread, i);
		str = brexit(str, red, &i);
		if (!str)
			return (NULL);
		if (!i)
			break ;
	}
	return (returned(str));
}
