#include "minirt.h"

int fill_camera(char **split, t_param *param)
{
	t_camera *t;

	t = &param->camera;
	if (ft_2d_arrlen(split) != 4)
		return (ERROR);
	if (is_coords(split[1], &t->p.x, &t->p.y, &t->p.z))
		return (printf(ERR_FILL_POSITION),ERROR);	
	if (is_vectors(split[2], &t->vec.x, &t->vec.y, &t->vec.z))
		return (ERROR);
	if (is_fov(split[3], &t->fov))
		return (ERROR);
	//printf("C: %f,%f,%f  %f,%f,%f  %d\n",t->p.x, t->p.y, t->p.z, t->vec.x, t->vec.y, t->vec.z, t->fov);
	return (OK);
}

int fill_ambiant(char **split, t_param *param)
{
	t_ambiant *t;

	t = &param->a_light;
	if (ft_2d_arrlen(split) != 3)
		return (ERROR);
	if (is_scale(split[1], &t->scale))
		return (printf(ERR_FILL_SCALE),ERROR);
	if (is_colors(split[2], &t->color.r, &t->color.g, &t->color.b))
		return (printf(ERR_FILL_COLORS),ERROR);
	//printf("A: %f %d %d %d\n", param->a_light.scale, param->a_light.color.r, param->a_light.color.g, param->a_light.color.b);
	return (OK);
}

int add_light(char **split, t_param *param)
{
	t_lights *new_light;

	new_light = create_light_node();
	if (!new_light)
		return (printf(ERR_MLC),ERROR);
	if (ft_2d_arrlen(split) != 4 || is_neg_deci_nb(split[2]))
		return (ERROR);
	if (is_coords(split[1], &new_light->p.x, &new_light->p.y, &new_light->p.z))
		return (printf(ERR_FILL_POSITION),ERROR);	
	if (is_scale(split[2], &new_light->scale))
		return (printf(ERR_FILL_SCALE),ERROR);
	if (is_colors(split[3], &new_light->color.r,&new_light->color.g, &new_light->color.b))
		return (printf(ERR_FILL_COLORS),ERROR);
	param->lights = insert_light_end(param->lights,new_light);
	//printf("l: %f %f %f %f %d %d %d\n",new_light->p.x, new_light->p.y, new_light->p.z, new_light->scale, new_light->color.r,new_light->color.g,new_light->color.b);
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
	//printf("R: %d x %d \n", param->window.width, param->window.height);
	return (OK);
}

int add_param(char **split, t_param *param)
{
	char type;

	type = split[0][0];
	if (type == 'c' && fill_camera(split, param))
		return (printf(ERR_CAM), ERROR);
	else if (type == 'A' && fill_ambiant(split, param))
		return (printf(ERR_AMB_LIGHT), ERROR);
	else if (type == 'l' && add_light(split, param))
		return (printf(ERR_LIGHT), ERROR);
	else if (type == 'R' && fill_window(split, param))
		return (printf(ERR_WINDOW), ERROR);
	else if (type != 'c' && type != 'A' && type != 'l' && type != 'R')
		return (printf(ERR_ADD_PARAM), ERROR);
	return (OK);
}
