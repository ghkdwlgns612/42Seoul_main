#include "../push.h"

bool    special_case_a(int rotate_num, t_stack *a, t_stack *b)
{
    if (rotate_num <= 3)
    {
        one_two_three(rotate_num,a,b,'A');
        return false;
    }
    else if (rotate_num == 5)
    {
        five(a,b,'A');
        return false;
    }
    else
        return true;
}

void    rollback_ra(t_stack *a, t_stack *b, t_inform *inform, int *res_cnt)
{
    int rrr;
    int rev_a;

    rrr = inform->rb;
    rev_a = inform->ra - inform->rb;
    if ((*res_cnt) > 0)
    {
        while (rrr--)
            all_stack_reverse_rotate(a,b,'C');
        while (rev_a--)
            one_stack_reverse_rotate(a, 'A');
    }
    else
    {
        while (rrr--)
            one_stack_reverse_rotate(b, 'B');
    }
}

void    rollback_rb(t_stack *a, t_stack *b, t_inform *inform, int *res_cnt)
{
    int rrr;
    int rev_b;

    rrr = inform->ra;
    rev_b = inform->rb - inform->ra;
    if ((*res_cnt) > 0)
    {
        while (rrr--)
            all_stack_reverse_rotate(a,b,'C');
        while (rev_b--)
            one_stack_reverse_rotate(b, 'B');
    }
    else
    {
        rrr = inform->rb;
        while (rrr--)
            one_stack_reverse_rotate(b, 'B');
    }
}

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

void    a_to_b(int rotate_num, t_stack *a, t_stack *b, int *res_cnt)
{
    int         temp;
    t_inform    *inform;

    inform = init_inform();
    temp = rotate_num;
    if (!special_case_a(rotate_num, a, b)) //rotate_num = 1,2,3,5면 실행하고 종료
    {
        free(inform);
        return ;
    }
    make_pivot(rotate_num, inform, a); //더블 피봇 생성
    while (temp--)
        ft_push_rotate_a(a,b,inform); //선별작업(제일 큰 그룹은 ra, 중간은 pb->rb, 제일 작은 것은 pb)
    if (inform->ra > inform->rb) //정렬 후 되돌리기 작업을 최소화하기 위해선택
        rollback_ra(a,b,inform,res_cnt);
    else
        rollback_rb(a,b,inform,res_cnt);
    a_to_b(inform->ra,a,b,res_cnt); //a스택 계속 정렬(1,2,3,5나올때까지)
    b_to_a(inform->rb,a,b,res_cnt); //b스택 정렬해서 a로 보내줌
    b_to_a(inform->pb - inform->rb,a,b,res_cnt); //나머지 제일작은 정렬 후 a로 보내줌.
    free(inform);
}