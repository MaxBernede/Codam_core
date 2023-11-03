#include "minirt.h"

int	to_decimal(char *s, float *f)
{
	int i;
	int negative;

	if (!cmp(s, "1"))
	{
		return (*f = 1, OK);
	}
	if (!cmp(s, "-1"))
		return (*f = -1, OK);
	if (!cmp(s, "0"))
		return ((*f = 0), OK);
	if (!cmp(s, "-0"))
		return ((*f = 0), OK);
	negative = 1.0;
	if (ft_strlen(s) > 6)
		return (ERROR);
	if (s[0] == '-')
	{
		negative = -1.0;
		s = s + 1;
	}
	if (ft_strncmp(s, "0.", 2))
		return (ERROR);
	if (ft_is_number(s+2))
		return (ERROR);
	i = ft_atoi(s+2);
	*f = i / 10.0;
	*f = *f * negative;
	return (OK);
}