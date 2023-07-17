/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 00:24:32 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/14 15:26:07 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// find diff between the R G B value then *porcent to get color
int	grad(int rstart, int rend, float pourcent)
{
	int	diff;
	int	ret;

	diff = rstart - rend;
	ret = rstart - (diff * pourcent / 100);
	return (ret);
}

// max value for x or y depending on the input char
int	maxintx(t_all *all, char c)
{
	int	i;
	int	max;
	int	maxy;

	i = 0;
	max = 0;
	maxy = 0;
	while (i < (all->nb_len * all->nb_lines))
	{
		if (max < all->coor[i].gridx)
			max = all->coor[i].gridx;
		if (maxy < all->coor[i].gridy)
			maxy = all->coor[i].gridy;
		++i;
	}
	if (c == 'x')
		return (max + 1);
	else
		return (maxy + 1);
}

void	ifprintpixel(t_coords *coor, mlx_image_t	*g_img, int i)
{
	if (coor[i].gridx > 0 && coor[i].gridx < WIDTH && \
	coor[i].gridy > 0 && coor[i].gridx < HEIGHT)
		mlx_put_pixel(g_img, coor[i].gridx, coor[i].gridy, \
		coor[i].color);
}

// give the decimal value for R G or B
int	hexavalue(char *c, int x)
{
	int		i;
	int		ret;
	char	*hexa;

	ret = 0;
	hexa = "0123456789ABCDEF";
	i = 0;
	while (i < 15 && hexa[i] != ft_toupper(c[x]))
		++i;
	ret = (i * 16);
	i = 0;
	while (i < 15 && hexa[i] != ft_toupper(c[x + 1]))
		++i;
	ret += i;
	return (ret);
}

void	leave(t_files *f, int fd)
{
	free(f->files);
	ft_free(f->splited);
	close(fd);
}
