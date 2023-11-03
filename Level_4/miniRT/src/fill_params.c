#include "minirt.h"

int fill_camera(char **split, t_param *param)
{
	t_camera *t;

	t = &param->camera;
	if (ft_2d_arrlen(split) != 4)
		return (ERROR);
	if (is_coords(split[1], &t->x, &t->y, &t->z))
		return (ERROR);	
	if (is_vectors(split[2], &t->vec_x, &t->vec_y, &t->vec_z))
		return (ERROR);
	if (is_fov(split[3], &t->fov))
		return (ERROR);
	printf("%d,%d,%d  %f,%f,%f  %d\n",t->x, t->y, t->z, t->vec_x, t->vec_y, t->vec_z, t->fov);
	return (OK);
}

int fill_ambiant(char **split, t_param *param)
{
	t_ambiant *t;

	t = &param->a_light;
	if (ft_2d_arrlen(split) != 3)
		return (ERROR);
	if (is_scale(split[1], &t->scale))
		return (ERROR);
	if (is_colors(split[2], &t->color.r, &t->color.g, &t->color.b))
		return (ERROR);
	printf("%f %d %d %d\n", param->a_light.scale, param->a_light.color.r, param->a_light.color.g, param->a_light.color.b);
	return (OK);
}

int add_light(char **split, t_param *param)
{
	
	return (OK);
}

int fill_window(char **split, t_param *param)
{
	if (ft_2d_arrlen(split) != 3 || ft_is_number(split[1]) || ft_is_number(split[2]))
		return (ERROR);
	if (ft_atoi_overflow(split[1], &param->window.width))
		return (ERROR);
	if (ft_atoi_overflow(split[2], &param->window.height))
		return (ERROR);
	printf("%d x %d \n", param->window.width, param->window.height);
	return (OK);
}

int add_param(char **split, t_param *param)
{
	if (split[0][0] == 'c' && fill_camera(split, param))
		return (printf(ERR_CAM), ERROR);
	else if (split[0][0] == 'A' && fill_ambiant(split, param))
		return (printf(ERR_AMB_LIGHT), ERROR);
	else if (split[0][0] == 'l' && add_light(split, param))
		return (printf(ERR_LIGHT), ERROR);
	else if (split[0][0] == 'R' && fill_window(split, param))
		return (printf(ERR_WINDOW), ERROR);
	return (OK);
}