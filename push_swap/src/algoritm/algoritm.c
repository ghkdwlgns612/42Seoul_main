#include "../push.h"

int     get_max_value(int size, t_node *node)
{
	int	max;

	max = node->value;
	while (size--)
	{
		if (max < node->value)
			max = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

int     get_min_value(int size, t_node *node)
{
	int	min;

	min = node->value;
	while (size--)
	{
		if (min > node->value)
			min = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}

void    make_pivot(int rotate_num, t_inform *inform, t_stack *stack)
{
    long max;
    long min;

    max = get_max_value(rotate_num, stack->top);
    min = get_min_value(rotate_num, stack->top);
    inform->pivot_max = (min + max) / 2;
    inform->pivot_min = (inform->pivot_max + min) / 2;
}

void    push_swap(t_stack *a, t_stack *b)
{
    a_to_b(a->size, a, b);
}