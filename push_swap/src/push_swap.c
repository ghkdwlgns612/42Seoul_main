#include "push.h"

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
        // printf("top : %d\n", a->top->value);
        // printf("next : %d\n", a->top->next->value);
        // printf("next : %d\n", a->bottom->prev->value);
        // printf("bottom : %d\n", a->bottom->value);   
        free(a);
        free(b);
    }
    return 0;
}