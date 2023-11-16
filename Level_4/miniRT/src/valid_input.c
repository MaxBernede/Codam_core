#include "minirt.h"

int open_file(char *arg)
{
	char *filepath;
	int fd;

	fd = open(arg, O_RDONLY);
	if (fd > 0)
		return (fd);
	filepath = ft_strjoin("./scenes/", arg);
	fd = open(filepath, O_RDONLY);
	if (fd > 0)
	{
		free(filepath);
		return (fd);
	}
	return (0);
}

bool endswith(char *str, char *suffix) {
    int str_len ;
    int suffix_len ;

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);

    if (str_len < suffix_len)
        return false;
    return (ft_strncmp(str + (str_len - suffix_len), suffix, suffix_len) == 0);
}

bool check_file(char *arg)
{
	if (!open_file(arg))
		return (printf(ERR_FILE), 1);
	if (!endswith(arg, ".rt"))
		return (printf(ERR_NORT), 1);
	return (OK);
}
