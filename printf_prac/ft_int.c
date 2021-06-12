#include "ft_printf.h"

void    ft_int_setting(inform_list *inform, va_list ap, char *buf)
{
    inform->width = ft_width(buf, ap, inform);
    inform->precision = ft_precision(buf, ap, inform);
    inform->num = va_arg(ap,int);
    inform->num_len = ft_int_length(inform->num);
    if (inform->width < 0)
            inform->width *= -1;
}

int    ft_int_main(va_list ap, inform_list *inform, char *buf) //25줄 애매
{
    char *res;
    int i;

    i = 0;
    ft_init(inform);
    i = ft_side_write(buf, i,inform) + 1;
    i = ft_flag(i, buf, inform);
    ft_int_setting(inform,ap,&buf[i]);
    if (inform->num == 0)
        ft_zero_printf(&res,inform);
    else
    {
        if (inform->is_dot == 1)
            ft_ignore_zero(&res,inform);
        else
            ft_zero_minus(&res,inform);
    }
   ft_write(res, (size_t)ft_strlen(res,inform));
    inform->res_len += ft_strlen(res,inform);
    i = ft_forward(buf, i);
   free(res);
    i = ft_side_write(buf, i,inform);
    return(inform->res_len);
}
