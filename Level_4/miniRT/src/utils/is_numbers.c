#include "minirt.h"

int is_numbers(char *a, char *b, char *c)
{
	if (ft_is_number(a) || ft_is_number(b) || ft_is_number(c))
		return (ERROR);
	return (OK);
}

int is_neg_numbers(char *a, char *b, char *c)
{
	if (ft_is_neg_number(a) || ft_is_neg_number(b) || ft_is_neg_number(c))
		return (ERROR);
	return (OK);
}

int is_neg_deci_numbers(char *a, char *b, char *c)
{
	if (is_neg_deci_nb(a) || is_neg_deci_nb(b) || is_neg_deci_nb(c))
		return (ERROR);
	return (OK);
}

//1 is ERROR
int ft_is_number(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (ERROR);
		i++;
	}
	return (OK);
}

int ft_is_neg_number(char *s)
{
	int i;

	i = 0;
	if (!cmp(s, "-"))
		return (ERROR);
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (ERROR);
		i++;
	}
	return (OK);
}

int is_neg_deci_nb(char *s)
{
	int i;

	i = 0;
	//printf("%s\n", s);
	if (!cmp(s, "-"))
		return (ERROR);
	if (s[i] == '-')
		s = s + 1;
	if (!cmp(s, "1"))
		return (OK);
	else if (!cmp(s, "0"))
		return (OK);
	if (ft_strncmp(s, "0.", 2))
		return (ERROR);
	if (ft_is_number(s+2))
		return (ERROR);
	return (OK);
}