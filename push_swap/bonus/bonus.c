#include "bonus.h"

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

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->top;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(stack);
}

void		free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

int     main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    if (argc > 1)
    {
        a = init_stack();
        b = init_stack();
        a->top = link_stack(&a,argc,argv);
        ft_check_duplicate(a->top);
        checker(a,b);
        free_all(a,b);
    }
    return 0;
}