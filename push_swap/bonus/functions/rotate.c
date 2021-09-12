#include "../bonus.h"

void    one_stack_rotate(t_stack *stack)
{
    t_node *temp;
    t_node *next;
    t_node *last;

    if ((stack)->size < 2)
        return ;

    temp = (stack)->top;
    next = (stack)->top->next;
    last = (stack)->bottom;
    (stack)->top = next;
    next->prev = NULL;
    
    if ((stack)->size == 2)
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
    (stack)->bottom = temp;
}

void    all_stack_rotate(t_stack *stack_a, t_stack *stack_b)
{
    one_stack_rotate(stack_a);
    one_stack_rotate(stack_b);
}