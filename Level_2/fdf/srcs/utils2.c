/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:34:42 by mbernede      #+#    #+#                 */
/*   Updated: 2023/03/13 16:33:58 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// count the length of arguments for the first line of the map
int	count_len_map(char *line)
{
	char	**splited;
	int		n;

	n = 0;
	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	while (splited[n])
		++n;
	ft_free(splited);
	return (n);
}

// fill black on background
void	fill_background(mlx_image_t *background)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(background, x, y, 0x000000FF);
	}
}

//write the string and return the ret value
int	returnstr(char *str, int ret)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
	return (ret);
}

//free str**
void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	check_leaks(void)
{
	system("leaks fdf");
}
