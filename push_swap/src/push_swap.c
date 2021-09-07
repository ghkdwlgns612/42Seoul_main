#include "push.h"


static void	free_stack(t_stack *stack)
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

//gcc -Wall -Wextra -Werror -g3 -fsanitize=address test.c 누수확인
int main(int argc, char *argv[]) 
{
    t_stack *a;
    t_stack *b;
    
    if (argc > 1) 
    {
        a = init_stack();
        b = init_stack();
        if (!a)
            ft_error();
        a->top = link_stack(&a,argc,argv);
        // printf("top_value : %d\n", a->top->value);
        // printf("top_next_value : %d\n", a->top->next->value);
        // printf("bottom_prev_value : %d\n", a->bottom->prev->value);
        // printf("bottom_value : %d\n", a->bottom->value);

        one_stack_rotate(&a,'A');

        // printf("top_value : %d\n", a->top->value);
        // printf("top_next_value : %d\n", a->top->next->value);
        // printf("bottom_prev_value : %d\n", a->bottom->prev->value);
        // printf("bottom_value : %d\n", a->bottom->value);   
        free_all(a,b);
    }
    return 0;
}