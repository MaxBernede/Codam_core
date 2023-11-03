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

typedef struct s_camera
{
	int x;
	int y;
	int z;
	float vec_x;
	float vec_y;
	float vec_z;
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
	int x;
	int y;
	int z;
	float scale;
	t_color color;
	struct s_light *next;
}	t_lights;

typedef struct s_element
{
	int x;
	int y;
	int z;
	t_type type;
	float scale;
	float radius;
	float height;
	t_color color;
	struct s_element *next;
}	t_element;
typedef struct s_param
{
	t_window	window;
	t_camera	camera;
	t_ambiant	a_light;
	t_lights	*lights;
	t_element	*element;
}	t_param;


#endif