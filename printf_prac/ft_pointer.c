#include "ft_printf.h"

void    ft_pointer_setting(inform_list *inform, va_list ap, char *buf)
{
    inform->width = ft_width(buf, ap, inform);
    inform->precision = ft_precision(buf, ap, inform);
    inform->pointer = va_arg(ap,unsigned long long);
    inform->num_len = ft_int_length(inform->num);
    if (inform->width < 0)
            inform->width *= -1;
}

void    ft_pointer_precision(char **res,inform_list *inform)
{
    
}

void    ft_pointer_width(char **res,inform_list *inform)
{
    if (inform->width == 0)
    {
        *res = (char *)malloc(inform->num_len + 1);
    }
    else
    {
        *res = (char *)malloc(inform->width + 1);
    }
}

int     ft_pointer_main(va_list ap,inform_list *inform, char *str)
{
    char *res;
    int i;

    i = 0;
    ft_init(inform);
    i = ft_side_write(str, i,inform) + 1;
    i = ft_flag(i, str, inform);
    ft_pointer_setting(inform,ap,&str[i]);
    if (inform->is_dot == 1)
        ft_pointer_precision(&res,inform);
    else
        ft_pointer_width(&res,inform);
    ft_write(res, (size_t)ft_strlen(res,inform));
    inform->res_len += ft_strlen(res,inform);
    i = ft_forward(str, i);
    free(res);
    i = ft_side_write(str, i,inform);
    return(inform->res_len);    
    return (1);
}