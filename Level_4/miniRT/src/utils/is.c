#include "minirt.h"

//ERROR == 1
int	is_colors(char *s, int *r, int *g, int *b)
{
	char **split;

	if (ft_strlen(s) > 11 || nb_or_comma(s))
		return (ERROR);
	split = ft_split(s, ',');
	if (!split)
		return (ERROR);
	if (ft_2d_arrlen(split) != 3)
		return (ft_2dfree(split), ERROR);
	*r = ft_atoi(split[0]);
	*g = ft_atoi(split[1]);
	*b = ft_atoi(split[2]);
	if (*r > 255 || *g > 255 || *b > 255)
		return (ft_2dfree(split), ERROR);
	return (ft_2dfree(split),OK);
}

//return ERROR == 1 in case of error otherwise fill the data
int is_scale(char *s, double *f)
{
	int i;

	if (ft_strlen(s) > 5)
		return (ERROR);
	if (!cmp(s, "1"))
		*f = 1;
	else if (!cmp(s, "0"))
		*f = 0;
	else
	{
		if (ft_strncmp(s, "0.", 2))
			return (ERROR);
		if (ft_is_number(s+2))
			return (ERROR);
		i = ft_atoi(s+2);
		*f = i / 10.0;
	}
	return (OK);
}
