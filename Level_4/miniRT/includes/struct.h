#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_node
{
	char					*name;
	char					*data;
	struct s_node			*next;
}	t_node;

typedef struct s_infos
{
	int						error;
	int						read_fd;
	int						write_fd;
	int						pipes[2];
	char					*pwd;
	t_node					*head;
}	t_infos;

#endif