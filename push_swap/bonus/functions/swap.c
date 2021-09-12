#include "../bonus.h"

void    one_stack_swap(t_stack *stack)
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
}

void    all_stack_swap(t_stack *stack_a, t_stack *stack_b)
{
    one_stack_swap(stack_a,name);
    one_stack_swap(stack_b,name);
}