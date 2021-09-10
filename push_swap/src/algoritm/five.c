#include "../push.h"

void    sort_b(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push_num;
	int	rotate;

	push_num = 0;
	rotate = 0;
	mid = get_mid_value(b->top);
	while (size--)
	{
		if (b->top->value >= mid)
		{
			push(b, a, 'A');
			push_num++;
		}
		else
		{
			one_stack_rotate(b, 'B');
			rotate++;
		}
		if (push_num == 3)
			break ;
	}
	while (rotate--)
		one_stack_reverse_rotate(b, 'B');
}

void    sort_a(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push_num;
	int	rotate;

	push_num = 0;
	rotate = 0;
	mid = get_mid_value(a->top);
	while (size--)
	{
		if (a->top->value >= mid)
		{
			push(a, b, 'B');
			push_num++;
		}
		else
		{
			one_stack_rotate(a, 'A');
			rotate++;
		}
		if (push_num == 3)
			break ;
	}
	while (rotate--)
		one_stack_reverse_rotate(a, 'A');
}

void    five(t_stack *a, t_stack *b,char name)
{
    if (name == 'A')
        sort_a(5,a,b);
    else
        sort_b(5,a,b);
    one_two_three(3,a,b,'A');
    one_two_three(2,a,b,'B');
}