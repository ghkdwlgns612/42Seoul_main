#include "push.h"

t_stack			*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void    link_node(t_node **node, t_node **temp_node, t_stack **stack_a)
{
    if (!*node)
    {
        *node = *temp_node;
        (*stack_a)->top = *node;
    }
    else
    {
        (*node)->next = *temp_node;
        (*temp_node)->prev = *node;
        *node = (*node)->next; 
    }
}

bool    extract_value(char *str, t_node **node, t_stack **stack_a)
{
    char **temp;
    t_node *temp_node;
    int i;

    temp = ft_split(str,' ');
    if (!temp || !(*temp))
        return false;
    i = 0;
    while (temp[i])
    {
        temp_node = init_node();
        if (!temp_node)
            ft_error();
        temp_node->value = ft_atoi(temp[i]);
        link_node(node, &temp_node, stack_a);
        i++;
    }
    return true;
}

t_node *link_stack(t_stack **stack_a, int argc, char **argv)
{
    int     i;
    bool    flag;
    t_node  *node;
    
    i = 1;
    node = NULL;
    while(i < argc)
    {
        flag = extract_value(argv[i], &node, stack_a);
        if (flag == false)
            ft_error();
        i++;
    }
    if (node->next == NULL)
        (*stack_a)->bottom = node;
    while (node->prev != NULL) //첫 번째 노드가 나올때까지 반복
        node = node->prev;
    return node; //첫 번째노드 반환
}


int main(int argc, char *argv[]) 
{
    t_stack *a;
    t_stack *b;
    
    if (argc > 1) 
    {
        a = init_stack();
        if (!a)
            ft_error();
        a->top = link_stack(&a,argc,argv);
        printf("top : %d\n", a->top->value);
        printf("next : %d\n", a->top->next->value);
        printf("next : %d\n", a->bottom->prev->value);
        printf("bottom : %d\n", a->bottom->value);
    }
    return 0;
}