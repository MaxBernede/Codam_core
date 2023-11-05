#include "minirt.h"

t_shapes *create_shape_node() 
{
    t_shapes *new_shape;
	new_shape = (t_shapes *)malloc(sizeof(t_shapes));
    if (new_shape)
        new_shape->next = NULL;
    return new_shape;
}

t_shapes *insert_shape_start(t_shapes *head, t_shapes *new_shape) 
{
    if (new_shape) 
	{
        new_shape->next = head;
        return new_shape;
    }
    return head;
}

t_shapes *insert_shape_end(t_shapes *head, t_shapes *new_shape) 
{
	t_shapes *current;
    if (new_shape) 
	{
        new_shape->next = NULL;
        if (!head)
            return new_shape;
        current = head;
        while (current->next)
            current = current->next;
        current->next = new_shape;
    }
    return head;
}

void free_shapes_list(t_shapes *head) {
    t_shapes *temp;

	while (head) 
	{
		temp = head;
		head = head->next;
        free(temp);
    }
}

void print_shapes(t_shapes *head)
{
	while (head)
	{
		print_shape(head);
		head = head->next;
	}
}
