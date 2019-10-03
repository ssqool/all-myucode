#include <stdlib.h>

#ifndef _list_
#define _list_

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list *mx_create_node(void *data);

#endif
