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

//utils.c
int	cmp(char *s1, char *s2);

//valid_input.c
bool	check_file(char *arg);
int		open_file(char *arg);


#endif