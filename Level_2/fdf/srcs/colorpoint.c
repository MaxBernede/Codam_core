/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colorpoint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 17:49:51 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 19:11:23 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

uint	colorpointy(t_all *all, int i, int x)
{
	uint		diff;
	float		pourcent;
	float		m;
	t_colors	rgb;

	m = (float)all->coor[i - all->nb_len].gridx - (float)all->coor[i].gridx;
	diff = all->coor[i - all->nb_len].color - all->coor[i].color;
	pourcent = (float)x / m * 100;
	if (diff)
	{
		rgb.r = grad(all->coor[i].r, all->coor[i - all->nb_len].r, pourcent);
		rgb.g = grad(all->coor[i].g, all->coor[i - all->nb_len].g, pourcent);
		rgb.b = grad(all->coor[i].b, all->coor[i - all->nb_len].b, pourcent);
		diff = (rgb.r * 16777216) + (rgb.g * 65536) + (rgb.b * 256) + 255;
	}
	else
		diff = all->coor[i].color;
	return (diff);
}

// find the right color for each pixel printed in linex or liney
uint	colorpoint(t_coords *coor, int i, int x)
{
	uint		diff;
	float		pourcent;
	float		m;
	t_colors	rgb;

	m = (float)coor[i + 1].gridx - (float)coor[i].gridx;
	diff = coor[i + 1].color - coor[i].color;
	pourcent = (float)x / m * 100;
	if (diff)
	{
		rgb.r = grad(coor[i].r, coor[i + 1].r, pourcent);
		rgb.g = grad(coor[i].g, coor[i + 1].g, pourcent);
		rgb.b = grad(coor[i].b, coor[i + 1].b, pourcent);
		diff = (rgb.r * 16777216) + (rgb.g * 65536) + (rgb.b * 256) + 255;
	}
	else
		diff = coor[i].color;
	return (diff);
}
