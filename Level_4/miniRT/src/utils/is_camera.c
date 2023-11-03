#include "minirt.h"

int	is_fov(char *s, int *fov)
{
	if (ft_strlen(s) > 3 || ft_is_number(s))
		return (ERROR);
	*fov = ft_atoi(s);
	if (*fov > 170 || *fov < 1)
		return (ERROR);
	return (OK);
}

int	is_coords(char *s, int *x, int *y, int *z)
{
	char **split;

	split = ft_split(s, ',');
	if (!split)
		return (ERROR);
	if (ft_2d_arrlen(split) != 3)
		return (ft_2dfree(split), ERROR);
	if (is_neg_numbers(split[0], split[1], split[2]))
		return (ft_2dfree(split), ERROR);
	*x = ft_atoi(split[0]);
	*y = ft_atoi(split[1]);
	*z = ft_atoi(split[2]);
	if ((*x > 10000 && *x < 10000)|| (*y > 10000 && *y < 10000)\
	 ||(*z > 10000 && *z < 10000))
		return (ft_2dfree(split), ERROR);
	return (ft_2dfree(split), OK);
}

int	is_vectors(char *s, float *vx, float *vy, float *vz)
{
	char **split;

	split = ft_split(s, ',');
	if (!split)
		return (ERROR);
	if (ft_2d_arrlen(split) != 3)
		return (ft_2dfree(split), ERROR);
	if (is_neg_deci_numbers(split[0], split[1], split[2]))
		return (ft_2dfree(split), ERROR);
	if (to_decimal(split[0], vx) || to_decimal(split[1], vy) || to_decimal(split[2], vz))
		return (ft_2dfree(split), ERROR);
	return (ft_2dfree(split),OK);
}