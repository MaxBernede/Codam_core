#include "minirt.h"

void my_hook(void* param)
{
	t_param *p;
	
	p = param;
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(p->mlx);
	if (mlx_is_key_down(p->mlx, MLX_KEY_UP))
		p->img->instances[0].y -= 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_DOWN))
		p->img->instances[0].y += 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		p->img->instances[0].x -= 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		p->img->instances[0].x += 5;
}
