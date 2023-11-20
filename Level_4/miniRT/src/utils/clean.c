#include "minirt.h"

void clean_everything(t_param *param)
{
	free_light_list(param->lights);
	free_shapes_list(param->shapes);
}