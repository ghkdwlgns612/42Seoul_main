#ifndef PUSH_H
#define PUSH_H
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX = 2147483647;
#define INT_MIN = -2147483648;

typedef struct		s_node
{
    int     value;
    struct s_node  *prev;
    struct s_node  *next;
}					t_node;

typedef struct s_stack
{
    int     size;
    t_node  *top;
    t_node  *bottom;
}              t_stack;


long long	    ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int    ft_check_arg(const char *str);

#endif