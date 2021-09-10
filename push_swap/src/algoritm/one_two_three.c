#include "../push.h"

void    two(t_stack *a, t_stack *b, char name)
{
    if (name == 'A')
    {
        if (a->top->value > a->top->next->value)
            one_stack_swap(a,'A');
    }
    else
    {
        if (b->top->value < b->top->next->value)
            one_stack_swap(b,'B');
        push(b,a,'A');
        push(b,a,'A');
    }
}

void    one_two_three(int rotate_num, t_stack *a, t_stack *b, char name)
{
    if (rotate_num == 3)
    {
        if (name == 'A')
            three_a(a);
        else
            three_b(a,b);
    }
    else if (rotate_num == 2)
        two(a,b,name);
    else if (rotate_num == 1)
    {
        if (name == 'B')
            push(b,a,'A');
    }
}