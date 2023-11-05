#ifndef STRUCT_H
#define STRUCT_H

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
	float x;
	float y;
	float z;
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
	float scale;
	t_color color;
}	t_ambiant;

typedef struct s_window
{
	int width;
	int height;
}	t_window;
typedef struct s_light
{
	float scale;
	t_position p;
	t_color color;
	struct s_light *next;
}	t_lights;

typedef struct s_shapes
{
	t_type type;
	t_position p;
	t_position vec;
	t_triangle t;
	float scale;
	float radius;
	float height;
	t_color color;
	struct s_shapes *next;
}	t_shapes;
typedef struct s_param
{
	t_window	window;
	t_camera	camera;
	t_ambiant	a_light;
	t_lights	*lights;
	t_shapes	*shapes;
}	t_param;


#endif