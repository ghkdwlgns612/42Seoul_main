#include "push.h"

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
        a->top = link_stack(&a,argc,argv); //할당 된 a스택을 넘겨서 argv[1]의 원소들을 파싱하여 링크드 리스트로 만들어줍니다. 
        ft_check_duplicate(a->top); //중복체크와 유효한 범위를 가지는지 체크
        if (is_sorted(a) || a->size == 1) //정렬되어있거나 크기가 1인것은 바로 종료
        {
            free_all(a,b);
            return 0;
        }
        push_swap(a,b); //여기까지 왔으면 정렬을 해보자.
        free_all(a,b);
    }
    return 0;
}