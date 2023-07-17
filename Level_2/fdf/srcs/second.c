/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   second.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 13:55:23 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 19:09:52 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	fill_nb(t_all *all, int i, t_nb *nb, char c)
{
	if (c == 'x')
	{
		nb->y = 0;
		nb->ymth = mathx(all, i, nb->x);
		nb->ynxt = mathx(all, i, nb->x + 1);
	}
	else
	{
		nb->y = 0;
		nb->ymth = mathy(all, i, nb->x);
		nb->ynxt = mathy(all, i, nb->x + 1);
	}
}

void	linex(t_all *all, int i)
{
	t_nb	nb;
	uint	color;

	nb.x = 0;
	while ((nb.x + all->coor[i].gridx) != all->coor[i + 1].gridx)
	{
		fill_nb(all, i, &nb, 'x');
		color = colorpoint(all->coor, i, nb.x);
		while ((nb.y + nb.ymth) != nb.ynxt)
		{
			mlx_put_pixel(all->g_img, nb.x + all->coor[i].gridx, \
			all->coor[i].gridy + nb.ymth + nb.y, color);
			if ((nb.y + nb.ymth) < nb.ynxt)
				++nb.y;
			else if ((nb.y + nb.ymth) > nb.ynxt)
				--nb.y;
		}
		mlx_put_pixel(all->g_img, nb.x + all->coor[i].gridx, \
		all->coor[i].gridy + nb.ymth + nb.y, color);
		if (all->coor[i].gridx < all->coor[i + 1].gridx)
			++nb.x;
		else
			--nb.x;
	}
}

void	liney(t_all *all, int i)
{
	t_nb	nb;
	uint	color;

	nb.x = 0;
	while ((nb.x + all->coor[i].gridx) != all->coor[i - all->nb_len].gridx)
	{
		fill_nb(all, i, &nb, 'y');
		color = colorpointy(all, i, nb.x);
		while ((nb.y + nb.ymth) != nb.ynxt)
		{
			mlx_put_pixel(all->g_img, nb.x + all->coor[i].gridx, \
			all->coor[i].gridy + nb.y + nb.ymth, color);
			if ((nb.y + nb.ymth) < nb.ynxt)
				++nb.y;
			else if ((nb.y + nb.ymth) > nb.ynxt)
				--nb.y;
		}
		mlx_put_pixel(all->g_img, all->coor[i].gridx + nb.x, \
		all->coor[i].gridy + nb.ymth, color);
		if ((nb.x + all->coor[i].gridx) < all->coor[i - all->nb_len].gridx)
			++nb.x;
		else
			--nb.x;
	}
}

//DRAW THE DOTS AND LINES
void	gridline(t_all *all)
{
	int	i;

	i = 0;
	while (i < (all->nb_len * all->nb_lines))
	{
		if (all->coor[i].x + 1 < all->nb_len)
			linex(all, i);
		if (all->coor[i].z != 0)
			liney(all, i);
		ifprintpixel(all->coor, all->g_img, i);
		++i;
	}
}

//MAIN FOR MLX42
int	screen(t_all *all)
{
	mlx_image_t	*background;

	gridxy(all);
	all->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!all->mlx)
		return (0);
	background = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	if (!background)
		return (returnstr("\nBackground image creation failed\n", 0));
	fill_background(background);
	mlx_image_to_window(all->mlx, background, 0, 0);
	all->g_img = mlx_new_image(all->mlx, maxintx(all, 'x'), maxintx(all, 'y'));
	if (!all->g_img)
		return (returnstr("\nMap creation failed\n", 0));
	mlx_image_to_window(all->mlx, all->g_img, 0, 0);
	gridline(all);
	all->g_img->instances[0].x -= maxintx(all, 'x') / 3;
	all->g_img->instances[0].y -= maxintx(all, 'y') / 3;
	mlx_loop_hook(all->mlx, &hook, all);
	mlx_loop(all->mlx);
	return (0);
}
