#include "../push.h"

void    ft_push_rotate_a(t_stack *a, t_stack *b, t_inform *inform)
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
        if (b->top->value >= inform->pivot_min)
        {
            one_stack_rotate(b,'B');
            inform->rb++;
        }
    }
}

void    a_to_b(int rotate_num, t_stack *a, t_stack *b)
{
    int         temp;
    int         temp_ra;
    int         temp_rb;
    t_inform *inform;

    inform = init_inform();
    temp = rotate_num;
    if (temp < 2)
        return ;
    make_pivot(rotate_num, inform, a);
    while (temp--)
        ft_push_rotate_a(a,b,inform);
    temp_ra = inform->ra;
    temp_rb = inform->rb;
    while (temp_ra--)
        ft_roll_back_a();
    while (temp_rb--)
        ft_roll_back_b();
    a_to_b(inform->ra,a,b);
    b_to_a(inform->rb,a,b);
    b_to_a(inform->pb - inform->rb,a,b);
    free(inform);
}