#include "ft_printf.h"

void    ft_init(inform_list *inform)
{
    inform->precision = 0;
    inform->width = 0;
    inform->zero_flag = 0;
    inform->minus_flag = 0;
    inform->is_dot = 0;
    inform->res_len = 0;
}

int    ft_side_write(char *str, int i,inform_list *inform)
{
    while (str[i] != '%' && str[i] != '\0')
    {
        inform->res_len++;
        write(1,&str[i++],1);
    }
    return (i);
}

int    ft_forward(char *str,int i)
{
    while (str[i] != 'd' && str[i] != 'c' && str[i] != 's')
        i++;
    i++;
    return (i);
}

