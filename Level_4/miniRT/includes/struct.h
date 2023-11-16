#ifndef STRUCT_H
#define STRUCT_H

#include "../MLX42/include/MLX42/MLX42.h"
typedef enum s_type
{
	PLANE,
	SPHERE,
	CYLINDER,
	SQUARE,
	TRIANGLE,
}	t_type;

typedef struct s_color
{
	int r;
	int g;
	int b;
}	t_color;

typedef struct s_position
{
	double x;
	double y;
	double z;
}	t_position;

typedef struct s_triangle
{
	t_position a;
	t_position b;
	t_position c;
}	t_triangle;
typedef struct s_camera
{
	t_position	p;
	t_position	vec;
	int fov;
}	t_camera;

typedef struct s_ambiant
{
	double scale;
	t_color color;
}	t_ambiant;

typedef struct s_window
{
	int width;
	int height;
}	t_window;
typedef struct s_light
{
	double scale;
	t_position p;
	t_color color;
	struct s_light *next;
}	t_lights;

typedef struct s_ray
{
	t_position	origin;
	t_position	direction;
}	t_ray;

typedef struct s_shapes
{
	t_type type;
	t_position p;
	t_position vec;
	t_triangle t;
	double scale;
	double radius;
	double height;
	t_color color;
	struct s_shapes *next;
}	t_shapes;
typedef struct s_param
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_window	window;
	t_camera	camera;
	t_ambiant	a_light;
	t_lights	*lights;
	t_shapes	*shapes;
}	t_param;


#endif