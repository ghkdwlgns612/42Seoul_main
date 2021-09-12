#include "../include/push.h"

bool    special_case_b(int rotate_num, t_stack *a, t_stack *b)
{
    if (rotate_num <= 3)
    {
        one_two_three(rotate_num,a,b,'B');
        return false;
    }
    else
        return true;
}

void    rollbacks_ra(t_stack *a, t_stack *b, t_inform *inform)
{
    int rrr;
    int rev_a;

    rrr = inform->rb;
    rev_a = inform->ra - inform->rb;
    while (rrr--)
        all_stack_reverse_rotate(a,b,'C');
    while (rev_a--)
        one_stack_reverse_rotate(a, 'A');
}

void    rollbacks_rb(t_stack *a, t_stack *b, t_inform *inform)
{
    int rrr;
    int rev_b;
    
    rrr = inform->ra;
    rev_b = inform->rb - inform->ra;
    while (rrr--)
        all_stack_reverse_rotate(a,b,'C');
    while (rev_b--)
        one_stack_reverse_rotate(b,'B');
}

void    ft_push_rotate_b(t_stack *a, t_stack *b, t_inform *inform)
{
    if (b->top->value <= inform->pivot_min)
    {
        one_stack_rotate(b,'B');
        inform->rb++;
    }
    else
    {
        push(b,a,'A');
        inform->pa++;
        if (a->top->value <= inform->pivot_max)
        {
            one_stack_rotate(a,'A');
            inform->ra++;
        }
    }
}

void    b_to_a(int rotate_num, t_stack *a, t_stack *b, int *res_cnt)
{
    int         temp;
    t_inform    *inform;

    (*res_cnt)++;
    inform = init_inform();
    temp = rotate_num;
    if (!special_case_b(rotate_num, a, b))
    {
        free(inform);
        return ;
    }
    make_pivot(rotate_num, inform, b);
    while (temp--)
        ft_push_rotate_b(a,b,inform);
    a_to_b(inform->pa - inform->ra,a,b,res_cnt);
    if (inform->ra > inform->rb)
        rollbacks_ra(a,b,inform);
    else
        rollbacks_rb(a,b,inform);
    a_to_b(inform->ra,a,b,res_cnt);
    b_to_a(inform->rb,a,b,res_cnt);
    free(inform);
}