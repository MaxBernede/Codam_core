#include "minirt.h"

int	to_decimal(char *s, float *f)
{
	//!TO BE ADDED OVERFLOWS CHECKS 
	//TODO overflows, specific error such as 1. as a data etc
	*f = ft_atof(s);
	return (OK);
}
