#include "minirt.h"

int nb_or_comma(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',')
			return (ERROR);
		i++;
	}
	return (OK);
}

void	ft_2d_print(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putstr_fd(str[i], 1);
		write(1, "\n", 1);
		++i;
	}
}

//0 is ==   -1 is error
int	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			++i;
		else
			return (-1);
	}
	if (s1[i] == s2[i])
		return (OK);
	else
		return (-1);
}
