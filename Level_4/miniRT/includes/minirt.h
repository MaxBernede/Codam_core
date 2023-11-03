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
#define ERR_ARG "Error: Not enough arguments to run\nShould be ./miniRT 'file.rt'\n"
#define ERR_FILE "Error: File given doesn't exist or no rights to access it\n"
#define ERR_NORT "Error: File doesn't end with .rt, cannot be accepted\n"
#define ERR_FILE_DATA "Error: File datas are not correct, exit\n"

#define ERR_CAM "Error: Camera informations incorrect\n"
#define ERR_AMB_LIGHT "Error: Ambiant lights informations incorrect\n"
#define ERR_LIGHT "Error: Lights informations incorrect\n"
#define ERR_WINDOW "Error: Window informations incorrect\n"

//fill_params.c
int add_param(char **split, t_param *param);

//parsing.c
int	fill_datas(char *arg, t_param *param);

//UTILS
//is_camera.c
int is_fov(char *s, int *fov);
int	is_coords(char *s, int *r, int *g, int *b);
int	is_vectors(char *s, float *r, float *g, float *b);

//is_numbers.c
int is_numbers(char *a, char *b, char *c);
int ft_is_number(char *s);
int is_neg_numbers(char *a, char *b, char *c);
int ft_is_neg_number(char *s);
int is_neg_deci_numbers(char *a, char *b, char *c);
int is_neg_deci_nb(char *s);

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