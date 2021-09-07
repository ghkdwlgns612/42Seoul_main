#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_node 
{
    int     value;
    struct s_node  *prev;
    struct s_node  *next;
}              t_node;

typedef struct s_stack
{
    int     size;
    t_node  *top;
    t_node  *bottom;
}              t_stack;




long long	ft_atoi(const char *str);
size_t	    ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
void	    ft_putendl_fd(char *s, int fd);
void	    ft_error();
# endif