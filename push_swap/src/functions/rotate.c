#include "../push.h"

void    one_stack_rotate(t_stack **stack, char name)
{
    t_node *temp;
    t_node *next;
    t_node *last;

    if ((*stack)->size < 2)
        return ;

    temp = (*stack)->top;
    next = (*stack)->top->next;
    last = (*stack)->bottom;
    (*stack)->top = next;
    next->prev = NULL;
    // printf("temp : %d\n",temp->value);
    // printf("next : %d\n",next->value);
    // printf("last : %d\n",last->value);
    
    if ((*stack)->size == 2)
    {
        temp->prev = next;
        temp->next = NULL;
        next->next = temp;
    }
    else
    {
        temp->next = NULL;
        last->next = temp;
        temp->prev = last;
    }
    (*stack)->bottom = temp;
    ft_print_rotate(name);
}

void    all_stack_rotate(t_stack **stack_a, t_stack **stack_b, char name)
{

}

void    ft_print_rotate(char name)
{
    if (name == 'A')
        ft_putendl_fd("pa", 1);
    else if (name == 'B')
        ft_putendl_fd("pb", 1);
}