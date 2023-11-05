#include "minirt.h"

int add_plane(char **split, t_param *param)
{
	t_shapes *s;

	s = create_shape_node();
	if (!s)
		return (printf(ERR_MLC),ERROR);
	if (ft_2d_arrlen(split) != 4)
		return (ERROR);
	s->type = PLANE;
	if (is_coords(split[1], &s->p.x, &s->p.y, &s->p.z))
		return (printf(ERR_FILL_POSITION),ERROR);	
	if (is_vectors(split[2], &s->vec.x, &s->vec.y, &s->vec.z))
		return (ERROR);
	if (is_colors(split[3], &s->color.r, &s->color.g, &s->color.b))
		return (printf(ERR_FILL_COLORS),ERROR);
	param->shapes = insert_shape_end(param->shapes, s);
	//printf("pl: %f,%f,%f  %f,%f,%f  %d %d %d\n",s->p.x, s->p.y, s->p.z, s->vec.x, s->vec.y, s->vec.z, s->color.r, s->color.g, s->color.b);
	return (OK);
}

int add_sphere(char **split, t_param *param)
{
	t_shapes *s;

	s = create_shape_node();
	if (!s)
		return (printf(ERR_MLC),ERROR);
	if (ft_2d_arrlen(split) != 4)
		return (ERROR);
	s->type = SPHERE;
	if (is_coords(split[1], &s->p.x, &s->p.y, &s->p.z))
		return (printf(ERR_FILL_POSITION),ERROR);	
	if (fill_float(split[2], &s->radius))
		return (printf(ERR_FILL_RADIUS),ERROR);
	if (is_colors(split[3], &s->color.r, &s->color.g, &s->color.b))
		return (printf(ERR_FILL_COLORS),ERROR);
	param->shapes = insert_shape_end(param->shapes, s);
	return (OK);
}

int add_square(char **split, t_param *param)
{
	t_shapes *s;

	s = create_shape_node();
	if (!s)
		return (printf(ERR_MLC),ERROR);
	if (ft_2d_arrlen(split) != 5)
		return (ERROR);
	s->type = SQUARE;
	if (is_coords(split[1], &s->p.x, &s->p.y, &s->p.z))
		return (printf(ERR_FILL_POSITION),ERROR);
	if (is_coords(split[2], &s->vec.x, &s->vec.y, &s->vec.z))
		return (printf(ERR_FILL_VECTOR),ERROR);
	if (fill_float(split[3], &s->scale))
		return (printf(ERR_FILL_SCALE),ERROR);
	if (is_colors(split[4], &s->color.r, &s->color.g, &s->color.b))
		return (printf(ERR_FILL_COLORS),ERROR);
	param->shapes = insert_shape_end(param->shapes, s);
	return (OK);
}

int add_cylinder(char **split, t_param *param)
{
	t_shapes *s;

	s = create_shape_node();
	if (!s)
		return (printf(ERR_MLC),ERROR);
	if (ft_2d_arrlen(split) != 6)
		return (ERROR);
	s->type = CYLINDER;
	if (is_coords(split[1], &s->p.x, &s->p.y, &s->p.z))
		return (printf(ERR_FILL_POSITION),ERROR);
	if (is_coords(split[2], &s->vec.x, &s->vec.y, &s->vec.z))
		return (printf(ERR_FILL_VECTOR),ERROR);
	if (fill_float(split[3], &s->radius))
		return (printf(ERR_FILL_RADIUS),ERROR);
	if (fill_float(split[4], &s->height))
		return (printf(ERR_FILL_HEIGHT),ERROR);
	if (is_colors(split[5], &s->color.r, &s->color.g, &s->color.b))
		return (printf(ERR_FILL_COLORS),ERROR);
	param->shapes = insert_shape_end(param->shapes, s);
	return (OK);
}

int add_triangle(char **split, t_param *param)
{
	t_shapes *s;

	s = create_shape_node();
	if (!s)
		return (printf(ERR_MLC),ERROR);
	if (ft_2d_arrlen(split) != 5)
		return (ERROR);
	s->type = TRIANGLE;
	if (is_coords(split[1], &s->t.a.x, &s->t.a.y, &s->t.a.z))
		return (printf(ERR_FILL_POSITION),ERROR);
	if (is_coords(split[2], &s->t.b.x, &s->t.b.y, &s->t.b.z))
		return (printf(ERR_FILL_POSITION),ERROR);
	if (is_coords(split[3], &s->t.c.x, &s->t.c.y, &s->t.c.z))
		return (printf(ERR_FILL_POSITION),ERROR);
	if (is_colors(split[4], &s->color.r, &s->color.g, &s->color.b))
		return (printf(ERR_FILL_COLORS),ERROR);
	param->shapes = insert_shape_end(param->shapes, s);
	return (OK);
}

int add_shape(char **split, t_param *param)
{
	char *type;

	type = split[0];
	if (!cmp(type, "pl") && add_plane(split, param))
		return (printf(ERR_PL), ERROR);
	else if (!cmp(split[0], "sp") && add_sphere(split, param))
		return (printf(ERR_SP), ERROR);
	else if (!cmp(split[0], "sq") && add_square(split, param))
		return (printf(ERR_SQ), ERROR);
	else if (!cmp(split[0], "cy") && add_cylinder(split, param))
		return (printf(ERR_CY), ERROR);
	else if (!cmp(split[0], "tr") && add_triangle(split, param))
		return (printf(ERR_TR), ERROR);
	else if (cmp(type, "pl") && cmp(type, "sp") && cmp(type, "sq") && cmp(type, "cy") && cmp(type, "tr"))
		return (printf(ERR_ADD_SHAPE), ERROR);
	return (OK);
}
