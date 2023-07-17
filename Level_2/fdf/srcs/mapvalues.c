/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapvalues.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 11:18:44 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 18:51:49 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// fill the colors values
void	getcolorintfromhexa(char *strcolor, t_all *all)
{
	int	n;

	if (strcolor[ft_strlen(strcolor) - 1] == '\n')
		strcolor[ft_strlen(strcolor) - 1] = '\0';
	n = all->b + (all->nb_len * all->a);
	if (ft_strlen(strcolor) == 4)
	{
		all->coor[n].r = 0;
		all->coor[n].g = 0;
		all->coor[n].b = hexavalue(strcolor, 2);
	}
	else if (ft_strlen(strcolor) == 6)
	{
		all->coor[n].r = 0;
		all->coor[n].g = hexavalue(strcolor, 2);
		all->coor[n].b = hexavalue(strcolor, 4);
	}
	else
	{
		all->coor[n].r = hexavalue(strcolor, 2);
		all->coor[n].g = hexavalue(strcolor, 4);
		all->coor[n].b = hexavalue(strcolor, 6);
	}
	all->coor[n].color = (all->coor[n].r * 16777216) + \
	(all->coor[n].g * 65536) + (all->coor[n].b * 256) + 255;
}

// fill the coordinates with values and color
int	fillcoor(t_all *all, char *splited)
{
	char	**intcolor;
	int		x;
	int		z;
	int		n;
	int		max;

	x = all->b;
	z = all->a;
	n = x + (all->nb_len * z);
	max = n * all->zoom * all->height;
	intcolor = ft_split(splited, ',');
	all->coor[n].x = x;
	all->coor[n].z = z;
	all->coor[n].y = ft_atoi(intcolor[0]);
	if (intcolor[1])
		getcolorintfromhexa(intcolor[1], all);
	else
		getcolorintfromhexa("0xFFFFFF", all);
	ft_free(intcolor);
	return (0);
}

void	fill(t_all *all, char *file)
{
	int		fd;
	t_files	f;

	f.files = ft_strjoin("./test_maps/", file);
	fd = open(f.files, O_RDONLY);
	f.line = get_next_line(fd);
	all->a = 0;
	while (f.line)
	{
		all->b = 0;
		f.splited = ft_split(f.line, ' ');
		free(f.line);
		while (f.splited[all->b])
		{
			if (fillcoor(all, f.splited[all->b]))
				return (leave(&f, fd));
			all->b += 1;
		}
		ft_free(f.splited);
		f.line = get_next_line(fd);
		all->a += 1;
	}
	free(f.line);
	free(f.files);
	close(fd);
}
