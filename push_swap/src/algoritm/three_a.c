#include "../push.h"

void	three_top_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->next->value == max)
		{
			one_stack_reverse_rotate(a, 'A');
			one_stack_swap(a, 'A');
		}
	}
	else
	{
		if (a->top->next->value == max)
		{
			one_stack_rotate(a, 'A');
			one_stack_swap(a, 'A');
			one_stack_reverse_rotate(a, 'A');
		}
	}
}

void	three_middle_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->bottom->value == max)
			one_stack_swap(a, 'A');
		else
			one_stack_rotate(a, 'A');
	}
	else
	{
		one_stack_swap(a, 'A');
		if (a->top->next->value == max)
		{
			one_stack_rotate(a, 'A');
			one_stack_swap(a, 'A');
			one_stack_reverse_rotate(a, 'A');
		}
	}
}

void	three_bottom_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->value == max)
			one_stack_swap(a, 'A');
		one_stack_reverse_rotate(a, 'A');
	}
	else
	{
		if (a->top->value == max)
			one_stack_swap(a, 'A');
		one_stack_rotate(a, 'A');
		one_stack_swap(a, 'A');
		one_stack_reverse_rotate(a, 'A');
		one_stack_swap(a, 'A');
	}
}

void    three_a(t_stack *a)
{
 	int	min;
	int	max;

	min = get_min_value(3, a->top);
	max = get_max_value(3, a->top);
	
	if (a->top->value == min)
		three_top_min_a(a, max);
	else if (a->top->next->value == min)
		three_middle_min_a(a, max);
	else if (a->top->next->next->value == min)
		three_bottom_min_a(a, max);
}