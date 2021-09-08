#include "../push.h"

int     get_max_value(t_stack *stack)
{
    t_node *node;
    int res;

    node = stack->top;
    res = node->value;
    while (node != NULL)
    {
        if (res < node->value)
            res = node->value;
        if (node->next != NULL)
            node = node->next;
        else
            break ;
    }
    while (node->prev != NULL)
        node = node->prev;
    return res;
}

int     get_min_value(t_stack *stack)
{
    t_node *node;
    int res;

    node = stack->top;
    res = node->value;
    while (node != NULL)
    {
        if (res > node->value)
            res = node->value;
        if (node->next != NULL)
            node = node->next;
        else
            break ;
    }
    while (node->prev != NULL)
        node = node->prev;
    return res;
}

void    push_swap(t_stack *a, t_stack *b)
{
    a_to_b(a->size, a, b, inform);
}