/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 11:06:32 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 19:11:59 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1080
# define HEIGHT 1080
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include "libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct coor
{
	int				x;
	int				y;
	int				z;
	int				gridx;
	int				gridy;
	int				r;
	int				g;
	int				b;
	unsigned int	color;
}	t_coords;

typedef struct all
{
	t_coords	*coor;
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	int			nb_lines;
	int			nb_len;
	int			zoom;
	int			height;
	int			a;
	int			b;
}	t_all;

typedef struct nb
{
	int	x;
	int	y;
	int	ymth;
	int	ynxt;
}	t_nb;

typedef struct files
{
	char	**splited;
	char	*line;
	char	*files;
}	t_files;

typedef struct rgb
{
	int	r;
	int	g;
	int	b;
}	t_colors;

//colorpoint.c
uint			colorpointy(t_all *all, int i, int x);
uint			colorpoint(t_coords *coor, int i, int x);

//mapvalues.c
int				hexavalue(char *c, int x);
void			getcolorintfromhexa(char *strcolor, t_all *all);
int				fillcoor(t_all *all, char *splited);
void			fill(t_all *all, char *file);

//grid.c
void			cleanpositive(t_all *all, int minx, int miny);
void			cleangridxy(t_all *all);
void			gridxy(t_all *all);
int				mathx(t_all *all, int i, int x);
int				mathy(t_all *all, int i, int x);

//main.c
int				map_data(t_all *all, char *file, int lines);
int				main(int argc, char **argv);

//hook.c
void			hook(void *param);

//second.c
void			fill_nb(t_all *all, int i, t_nb *nb, char c);
void			linex(t_all *all, int i);
void			liney(t_all *all, int i);
void			gridline(t_all *all);
int				screen(t_all *all);

//utils.c
int				grad(int rstart, int rend, float pourcent);
int				maxintx(t_all *all, char c);
void			ifprintpixel(t_coords *coor, mlx_image_t	*g_img, int i);
int				hexavalue(char *c, int x);
void			leave(t_files *f, int fd);

//utils2.c
int				count_len_map(char *line);
void			fill_background(mlx_image_t *background);
int				returnstr(char *str, int ret);
void			ft_free(char **str);
void			check_leaks(void);

#endif