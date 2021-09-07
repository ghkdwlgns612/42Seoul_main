#include "../push.h"

void    one_stack_reverse_rotate(t_stack **stack, char name)
{
    t_node *temp;
    t_node *last_prev;
    t_node *last;

    if ((*stack)->size < 2)
        return ;

    temp = (*stack)->top;
    last_prev = (*stack)->bottom->prev;
    last = (*stack)->bottom;
    (*stack)->top = last;
    last->prev = NULL;
    last->next = temp;
    temp->prev = last;
    if ((*stack)->size == 2)
        temp->next = NULL;
    else
        last_prev->next = NULL;
    (*stack)->bottom = last_prev;
    ft_print_reverse_rotate(name);
}

void    all_stack_reverse_rotate(t_stack **stack_a, t_stack **stack_b, char name)
{
    one_stack_reverse_rotate(stack_a,name);
    one_stack_reverse_rotate(stack_b,name);
    if (name == 'C')
        ft_putendl_fd("rrr", 1); 
}

void    ft_print_reverse_rotate(char name)
{
    if (name == 'A')
        ft_putendl_fd("rra", 1);
    else if (name == 'B')
        ft_putendl_fd("rrb", 1);
}