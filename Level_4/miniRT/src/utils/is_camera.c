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

int	is_coords(char *s, double *x, double *y, double *z)
{
	char **split;

	split = ft_split(s, ',');
	if (!split)
		return (ERROR);
	if (ft_2d_arrlen(split) != 3)
		return (ft_2dfree(split), ERROR);
	if (is_doubles(split[0], split[1], split[2]))
		return (ft_2dfree(split), ERROR);
	*x = ft_atof(split[0]);
	*y = ft_atof(split[1]);
	*z = ft_atof(split[2]);
	if ((*x > 10000 && *x < 10000)|| (*y > 10000 && *y < 10000)\
	 ||(*z > 10000 && *z < 10000))
		return (ft_2dfree(split), ERROR);
	return (ft_2dfree(split), OK);
}

//only works with 0. maybe make a iscoords and is vectors in one
int	is_vectors(char *s, double *vx, double *vy, double *vz)
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

//! TAKE CARE OVERFLOWS OR VALUE THAT ARE MAX 1 AND MIN 0
int	fill_double(char *s, double *f)
{
	// if (is_neg_deci_nb(s))
	// 	return (ERROR);
	if (to_decimal(s, f))
		return (ERROR);
	return (OK);
}