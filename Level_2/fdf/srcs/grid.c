/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 16:27:51 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 16:43:46 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// add the max negative value to only have positive ones
void	cleanpositive(t_all *all, int minx, int miny)
{
	int	i;

	i = 0;
	while (i < (all->nb_len * all->nb_lines))
	{
		if (minx)
			all->coor[i].gridx = all->coor[i].gridx - minx;
		if (miny)
			all->coor[i].gridy = all->coor[i].gridy - miny;
		++i;
	}
}

//search for the min grid x and grid y values to print only positive numbers
void	cleangridxy(t_all *all)
{
	int	i;
	int	minx;
	int	miny;

	i = 0;
	minx = 0;
	miny = 0;
	while (i < (all->nb_len * all->nb_lines))
	{
		if (all->coor[i].gridx < minx)
			minx = all->coor[i].gridx;
		if (all->coor[i].gridy < miny)
			miny = all->coor[i].gridy;
		++i;
	}
	if (minx < 0 || miny < 0)
		cleanpositive(all, minx, miny);
}

//scale is the zoom, I need to change the hardcoded values inside still
void	gridxy(t_all *all)
{
	int	y;
	int	x;
	int	half;

	y = 0;
	half = all->zoom / 2;
	while (y < all->nb_lines)
	{
		x = 0;
		while (x < all->nb_len)
		{
			all->coor[x + y * all->nb_len].gridx = (x - y) * all->zoom;
			all->coor[x + y * all->nb_len].gridy = (y + x) * half - \
			all->coor[x + y * all->nb_len].y * all->height;
			++x;
		}
		++y;
	}
	cleangridxy(all);
}

//mathx return an int for the x position of the point to print
// print if theres value to the right, from left to right
int	mathx(t_all *all, int i, int x)
{
	float	y;
	float	m;
	float	total;
	int		o;

	y = (float)all->coor[i + 1].gridy - (float)all->coor[i].gridy;
	m = (float)all->coor[i + 1].gridx - (float)all->coor[i].gridx;
	total = y / m;
	o = total * x;
	return (o);
}

// give back the y coordinate
// print if theres value above, from bottom to top
int	mathy(t_all *all, int i, int x)
{
	float	y;
	float	m;
	float	total;
	int		o;

	y = (float)all->coor[i - all->nb_len].gridy - (float)all->coor[i].gridy;
	m = (float)all->coor[i - all->nb_len].gridx - (float)all->coor[i].gridx;
	total = y / m;
	o = total * x;
	if (!y)
		return (0);
	return (o);
}
