/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 16:22:07 by mbernede      #+#    #+#                 */
/*   Updated: 2023/03/14 15:22:50 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	hook(void *param)
{
	t_all	*all;

	all = param;
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(all->mlx);
	if (mlx_is_key_down(all->mlx, MLX_KEY_UP))
		all->g_img->instances[0].y -= 25;
	if (mlx_is_key_down(all->mlx, MLX_KEY_DOWN))
		all->g_img->instances[0].y += 25;
	if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT))
		all->g_img->instances[0].x -= 25;
	if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT))
		all->g_img->instances[0].x += 25;
}
