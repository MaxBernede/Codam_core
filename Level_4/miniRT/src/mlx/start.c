#include "minirt.h"
#include <stdint.h>

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int start(t_param *param, t_window w)
{
	param->mlx = mlx_init(w.width, w.height, "minirt", true);
	if (!param->mlx)
		return (ERROR);
	param->img	= mlx_new_image(param->mlx, w.width, w.height);
	if (!param->img)
		return (mlx_close_window(param->mlx), ERROR);
	for (int y = 0; y < w.height; ++y) 
	{
        for (int x = 0; x < w.width; ++x)
		{
            int r = x;
            int g = y;
            int b = 0;
			mlx_put_pixel(param->img, x, y, ft_pixel(r, g, b, 255)); 
        }
	}
	if (mlx_image_to_window(param->mlx, param->img, 0, 0) == -1)
	{
		mlx_close_window(param->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_loop_hook(param->mlx, my_hook, param);

	mlx_loop(param->mlx);
	mlx_terminate(param->mlx);
	return (OK);
}