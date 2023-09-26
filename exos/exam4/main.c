#include "inc.h"

void    show(t_link *start)
{
    while (start)
    {
        printf("Value : %d\n",start->value);
        start = start->next;
    }
}

void    add(t_link *start, int value)
{
    t_link *new;

    new = malloc(sizeof(t_link *));
    new->next = NULL;
    new->value = value;
    while (start->next)
        start = start->next;
    start->next = new;
}

int main(int argc, char **argv)
{
    t_link *start;

    start = malloc(sizeof(t_link));
    start->value = 0;
    start->next = NULL;
    add(start, 2);
    add(start, 5);
    add(start, 6);
    add(start, 9);
    show(start);
    return 0;
}