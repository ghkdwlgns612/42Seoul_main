#include "../bonus.h"

int ft_check(const char *str) { //str -> 부호 제외하고 10자리인지 확인 -> long long변환 후 int_max , int_min랑 확인
    int i = 0;
    //숫자로 사용될수있는지 확인(1234, -1234, 12-34, 12a2, -12-12)
    while (str[i] != 0)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            if (!(i == 0 && str[i] == '-'))
                ft_error();
        }
        i++;
    }
    //정수범위내에 들어오는지 확인
    long long ret = ft_atoi(str);
    if (ret > 2147483647 || ret < -2147483648)
        ft_error();
    return (int)ret;
}

void    ft_check_duplicate(t_node *node)
{
    t_node *temp;
    int     value;
    while (node->next != NULL)
    {
        temp = node->next;
        value =  node->value;
        while (temp != NULL)
        {
            if (temp->value == value)
                ft_error();
            if (temp->next == NULL)
                break ;
            temp = temp->next;
        }
        node = node->next;
    }
    while (node->prev != NULL)
        node = node->prev;
}