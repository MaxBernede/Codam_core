#ifndef INC_H
#define INC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_link
{
    int     value;
    struct s_link  *next;
}   t_link;

#endif