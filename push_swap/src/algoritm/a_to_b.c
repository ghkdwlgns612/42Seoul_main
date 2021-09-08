#include "../push.h"

void    ft_push_rotate(t_stack *a, t_stack *b, t_inform *inform)
{
    if (a->top->value >= inform->pivot_max)
    {
        one_stack_rotate(a,'A');
        inform->ra++;
    }
    else
    {
        push(a,b,'B');
        inform->pb++;
        if (b->top-value >= inform->pivot_min)
        {
            one_stack_rotate(b,'B');
            inform->rb++;
        }
    }
}


void    make_pivot(t_inform *inform, t_stack *stack)
{
    long max;
    long min;

    max = get_max_value(a);
    min = get_min_value(a);
    inform->pivot_max = (min + max) / 2;
    inform->pivot_min = (inform->pivot_max + min) / 2;
}

void    a_to_b(int rotate_num, t_stack *a, t_stack *b, t_inform *inform)
{
    int         temp;
    t_inform *inform;

    inform = init_inform();
    temp = rotate_num;
    if (temp < 2)
        return ;
    make_pivot(inform, a);
    while (temp--)
        ft_push_rotate(a,b,inform);    
    free(inform);
}