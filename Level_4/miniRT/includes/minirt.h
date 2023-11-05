#ifndef MINIRT_H
#define MINIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "struct.h"
#include "libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define OK 0
#define ERROR 1

//Run errors
#define ERR_ARG "Error: Not enough arguments to run\nShould be ./miniRT 'file.rt'\n"
#define ERR_FILE "Error: File given doesn't exist or no rights to access it\n"
#define ERR_NORT "Error: File doesn't end with .rt, cannot be accepted\n"
#define ERR_FILE_DATA "Error: File datas are not correct, exit\n"

//Errors globals
#define ERR_MLC "Error: Malloc Failed\n"

//Errors fills
#define ERR_FILL_SCALE "Error: Error data filling the scale\n"
#define ERR_FILL_COLORS "Error: Error data filling the colors\n"
#define ERR_FILL_POSITION "Error: Error data filling the position\n"
#define ERR_FILL_VECTOR "Error: Error data filling the vector\n"
#define ERR_FILL_RADIUS "Error: Error data filling the radius\n"
#define ERR_FILL_HEIGHT "Error: Error data filling the height\n"
#define ERR_ADD_PARAM "Error: the first character of add param isn't correct\n"
#define ERR_ADD_SHAPE "Error: the type of shape from add shape isn't correct\n"


//Shape Error
#define ERR_PL "Error: Shape Plane fill\n"
#define ERR_SQ "Error: Shape Square fill\n"
#define ERR_SP "Error: Shape Sphere fill\n"
#define ERR_TR "Error: Shape Triangle fill\n"
#define ERR_CY "Error: Shape Cylinder fill\n"

#define ERR_CAM "Error: Camera informations incorrect\n"
#define ERR_AMB_LIGHT "Error: Ambiant lights informations incorrect\n"
#define ERR_LIGHT "Error: Lights informations incorrect\n"
#define ERR_WINDOW "Error: Window informations incorrect\n"

//fill_params.c
int add_param(char **split, t_param *param);

//parsing.c
int	fill_datas(char *arg, t_param *param);

//!LIGHTS
t_lights *create_light_node();
t_lights *insert_light_start(t_lights *head, t_lights *new_light);
t_lights *insert_light_end(t_lights *head, t_lights *new_light);
void free_light_list(t_lights *head);
void print_lights(t_lights *head);

//!SHAPES
int add_shape(char **split, t_param *param);

t_shapes *create_shape_node();
t_shapes *insert_shape_start(t_shapes *head, t_shapes *new_light);
t_shapes *insert_shape_end(t_shapes *head, t_shapes *new_light);
void free_shapes_list(t_shapes *head);
void print_shapes(t_shapes *head);

//!UTILS
//prints.c
void print_shape(t_shapes *s);
void print_param(t_param *param);
void print_light(t_lights *light);

//clean.c
void clean_everything(t_param *param);

//ft_atof.c
float ft_atof(char *nptr);
//is_camera.c
int is_fov(char *s, int *fov);
int	is_coords(char *s, float *x, float *y, float *z);
int	is_vectors(char *s, float *r, float *g, float *b);
int	fill_float(char *s, float *f);

//is_numbers.c
int is_numbers(char *a, char *b, char *c);
int ft_is_number(char *s);
int is_neg_numbers(char *a, char *b, char *c);
int ft_is_neg_number(char *s);
int is_neg_deci_numbers(char *a, char *b, char *c);
int is_neg_deci_nb(char *s);
int is_floats(char *a, char *b, char *c);
int ft_is_f(char *s);

//to.c
int	to_decimal(char *s, float *f);

int is_scale(char *s, float *f);
int	is_colors(char *s, int *r, int *g, int *b);

//fill_to_null.c
void	init_null(t_param *param);

void	ft_2d_print(char **str);
int	cmp(char *s1, char *s2);
int nb_or_comma(char *s);

//valid_input.c
bool	check_file(char *arg);
int		open_file(char *arg);


#endif