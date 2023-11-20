#include "minirt.h"

t_lights *create_light_node()
{
	t_lights *new_light;

	new_light = (t_lights *)malloc(sizeof(t_lights));
	if (new_light)
		new_light->next = NULL;
	return new_light;
}

t_lights *insert_light_start(t_lights *head, t_lights *new_light)
{
	if (new_light) 
	{
		new_light->next = head;
		return new_light;
	}
	return head;
}

t_lights *insert_light_end(t_lights *head, t_lights *new_light)
{
	t_lights *current;

	if (new_light) 
	{
		new_light->next = NULL;
		if (!head)
			return new_light;
		current = head;
		while (current->next)
			current = current->next;
		current->next = new_light;
	}
	return head;
}

void free_light_list(t_lights *head)
{
	t_lights *temp;

	while (head) 
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void print_lights(t_lights *head)
{
	while (head)
	{
		print_light(head);
		head = head->next;
	}
}
