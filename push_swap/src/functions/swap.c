#include "../push.h"

void    ft_print_swap(char name)
{
    if (name == 'A')
		ft_putendl_fd("sa", 1);
    else if (name == 'B')
		ft_putendl_fd("sb", 1);
}

void    one_stack_swap(t_stack *stack, char name)
{
    t_node *temp;
    t_node *next;

    if ((stack)->size < 2)
        return ;
    temp = (stack)->top;
    next = (stack)->top->next;
    (stack)->top = next;    
    next->prev = NULL;
    temp->prev = next;
    if ((stack)->size == 2)
    {
        temp->next = NULL;
        next->next = temp;
        (stack)->bottom = temp;
    }
    else
    {   
        temp->next = next->next;
        next->next->prev = temp;
        next->next = temp;
    }
    ft_print_swap(name);
}

void    all_stack_swap(t_stack *stack_a, t_stack *stack_b, char name)
{
    one_stack_swap(stack_a,name);
    one_stack_swap(stack_b,name);
    if (name == 'C')
        ft_putendl_fd("ss", 1);
}