#include "../push.h"

void		arg_five(t_stack *a, t_stack *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = get_mid_value(a->top);
	while (1)
	{
		if (a->top->value < mid)
		{
			push(a, b, 'B');
			pb++;
		}
		else
			one_stack_rotate(a, 'A');
		if (pb == 2)
			break ;
	}
	three_a(a);
	two(a, b, 'B');
}