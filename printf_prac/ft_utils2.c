#include "ft_printf.h"

void    ft_init(inform_list *inform)
{
    inform->type = 0;
    inform->precision = 0;
    inform->width = 0;
    inform->zero_flag = 0;
    inform->minus_flag = 0;
    inform->is_dot = 0;
    inform->res_len = 1;
}


int     ft_num(va_list ap)
{
    return (va_arg(ap,int));
}

int    ft_forward(char *str,int i)
{
    while (str[i] != 'd')
        i++;
    i++;
    return (i);
}

