#include "minirt.h"

int add_element(char **split, t_param *param)
{

}

//check if needed to split based on isspace
int check_line(char *line, t_param *param)
{
	char **split;
	char *sub;

	//removed the \n of the line 
	sub = ft_substr(line, 0, ft_strlen(line)-1);
	if (!sub || !sub[0] || sub[0] == '#')
		return (OK);
	split = ft_split(sub, ' ');
	free(sub);
	if (ft_strlen(split[0]) == 2 && add_element(split, param))
			return (ft_2dfree(split), ERROR);
	else if (ft_strlen(split[0]) == 1 && add_param(split, param))
			return (ft_2dfree(split), ERROR);
	ft_2dfree(split);
	return (OK);
}

int fill_datas(char *arg, t_param *param)
{
	int fd;
	char *line;

	fd = open_file(arg);
	if (fd <= 0)
		return (ERROR);
	line = get_next_line(fd);
	while (line)
	{
		if (check_line(line, param))
			return (free(line), printf(ERR_FILE_DATA), ERROR);
		free(line);
		line = get_next_line(fd);
	}
	return (OK);
}