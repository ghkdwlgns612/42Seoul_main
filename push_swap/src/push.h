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

typedef struct  s_stack
{
    int         size;
    t_node      *top;
    t_node      *bottom;
}               t_stack;

t_stack			*init_stack(void);
t_node	        *init_node(void);
void            link_node(t_node **node, t_node **temp_node, t_stack **stack_a);
bool            extract_value(char *str, t_node **node, t_stack **stack_a);
t_node          *link_stack(t_stack **stack_a, int argc, char **argv);

long long	    ft_atoi(const char *str);
size_t	        ft_strlen(const char *str);
char		    **ft_split(char const *s, char c);
void	        ft_putendl_fd(char *s, int fd);
void	        ft_error();

int             ft_check(const char *str);
void            ft_dup_check(t_stack *stack);

void            one_stack_swap(t_stack *stack, char name);
void            all_stack_swap(t_stack *stack_a, t_stack *stack_b, char name);
void            ft_print_swap(char name);

void            one_stack_rotate(t_stack *stack, char name);
void            all_stack_rotate(t_stack *stack_a, t_stack *stack_b, char name);
void            ft_print_rotate(char name);

void            one_stack_reverse_rotate(t_stack *stack, char name);
void            all_stack_reverse_rotate(t_stack *stack_a, t_stack *stack_b, char name);
void            ft_print_reverse_rotate(char name);

void            one_size_push(t_stack *poped, t_stack *pushed);
void            general_push(t_stack *poped, t_stack *pushed);
void            push(t_stack *poped, t_stack *pushed, char name);
void            ft_print_push(char name);

# endif