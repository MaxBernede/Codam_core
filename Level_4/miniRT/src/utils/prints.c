#include "minirt.h"

void	print_pos(t_position pos)
{
	printf("(%.2f,%.2f,%.2f) ", pos.x, pos.y, pos.z);
}

void	print_color(t_color color)
{
	printf("colors:(%d,%d,%d) ", color.r, color.g, color.b);
}

void print_shape(t_shapes *s)
{
	const char* type[] = {"pl","sp","sq","cy","tr"};

	printf("%s ",type[s->type]);
	print_pos(s->p);
	print_color(s->color);
	if (s->type == PLANE || s->type == SQUARE || s->type == CYLINDER)
		print_pos(s->vec);
	if (s->type == SPHERE || s->type == CYLINDER)
		printf("%.2f ",s->radius);
	if (s->type == SQUARE)
		printf("%.2f %.2f ",s->scale, s->height);
	printf("\n");
}

void print_light(t_lights *light)
{
	printf("l Scale:%2.f ",light->scale);
	print_pos(light->p);
	print_color(light->color);
	printf("\n");
}

void print_param(t_param *param)
{
	printf("Window : %d x %d\n",param->window.width, param->window.height);
	printf("Ambient light: %.2f ",param->a_light.scale);
	print_color(param->a_light.color);
	printf("\nCamera: FOV:%d ",param->camera.fov);
	print_pos(param->camera.p);
	print_pos(param->camera.vec);
	printf("\n");
	print_lights(param->lights);
	print_shapes(param->shapes);
}