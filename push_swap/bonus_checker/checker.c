#include "bonus.h"

bool		ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (s1[index] == s2[index])
	{
		if (s1[index] == '\0' && s2[index] == '\0')
			return (false);
		index++;
	}
	if (s1[index] > s2[index])
		return (true);
	else
		return (true);
}


bool    is_sorted(t_stack *stack)
{
    t_node	*node;

	node = stack->top;
	while (node != NULL)
	{
		if (node->next != NULL)
		{
			if (node->value > node->next->value)
				return false;
		}
		if (node->next != NULL)
			node = node->next;
		else
			break ;
	}
	if (node->value == stack->bottom->value)
		return true;
	else
		return false;
}

void	check_functions(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("pa", buf))
        push(b,a);
    else if (!ft_strcmp("pb", buf))
        push(a,b);
	else if (!ft_strcmp("sa", buf))
        one_stack_swap(a);
    else if (!ft_strcmp("sb", buf))
        one_stack_swap(b);
    else if (!ft_strcmp("ss", buf))
        all_stack_swap(a,b);
    else if (!ft_strcmp("ra", buf))
        one_stack_rotate(a);
    else if (!ft_strcmp("rb", buf))
        one_stack_rotate(b);
    else if (!ft_strcmp("rr", buf))
        all_stack_rotate(a,b);
    else if (!ft_strcmp("rra", buf))
        one_stack_reverse_rotate(a);
    else if (!ft_strcmp("rrb", buf))
        one_stack_reverse_rotate(b);
    else if (!ft_strcmp("rrr", buf))
        all_stack_reverse_rotate(a,b);
	else
		ft_error();
}

void	checker(t_stack *a, t_stack *b)
{
	char	*buf;

	while (get_next_line(0, &buf) > 0)
	{
		check_functions(buf, a, b);
		free(buf);
	}
	free(buf);
	if (is_sorted(a) && !b->top)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}