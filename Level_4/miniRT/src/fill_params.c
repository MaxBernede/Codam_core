#include "minirt.h"

int fill_camera(char **split, t_param *param)
{
	//if ()
	return (OK);
}

//ERROR == 1
int	is_colors(char *s, int *r, int *g, int *b)
{
	char **split;

	if (ft_strlen(s) > 11)
		return (ERROR);
	split = ft_split(s, ',');
	if (!split)
		return (ERROR);
	if (ft_2d_arrlen(split) != 3)
		return (ft_2dfree(split), ERROR);
	
	return (OK);
}

//return ERROR == 1 in case of error otherwise fill the data
int is_scale(char *s, float *f)
{
	int i;

	if (ft_strlen(s) > 5)
		return (ERROR);
	if (!cmp(s, "1"))
		*f = 1;
	else if (!cmp(s, "0"))
		*f = 0;
	else
	{
		if (ft_strncmp(s, "0.", 2))
			return (ERROR);
		i = ft_atoi(s+2);
		*f = i / 10.0;
	}
	return (OK);
}

int fill_ambiant(char **split, t_param *param)
{
	t_ambiant *t;

	t = &param->light;
	if (ft_2d_arrlen(split) != 3)
		return (ERROR);
	if (is_scale(split[1], &t->scale))
		return (ERROR);
	if (is_colors(split[2], &t->color.r, &t->color.g, &t->color.b))
		return (ERROR);
	printf("%f %d %d %d\n", param->light.scale, param->light.color.r, param->light.color.g, param->light.color.b);
	return (OK);
}

int add_light(char **split, t_param *param)
{
	return (OK);
}

int fill_window(char **split, t_param *param)
{
	int width;
	int height;

	if (ft_2d_arrlen(split) != 3)
		return (ERROR);
	if (ft_atoi_overflow(split[1], &width))
		return (ERROR);
	if (ft_atoi_overflow(split[2], &height))
		return (ERROR);
	param->window.width = width;
	param->window.height = height;
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