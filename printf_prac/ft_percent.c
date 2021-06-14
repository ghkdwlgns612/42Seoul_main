#include "ft_printf.h"

void    ft_percent_setting(inform_list *inform, va_list ap, char *buf)
{
    inform->width = ft_width(buf, ap, inform);
    inform->precision = ft_precision(buf, ap, inform);
    if (inform->width < 0)
    {
        inform->width *= -1; 
        inform->minus_flag = 1;
    }   
}

void    ft_write1_percent(char *res, inform_list *inform)
{
    int i;

    i = 0;
    if (inform->minus_flag == 1)
    {
        res[i++] = '%';
        while (i < inform->width)
            res[i++] = ' ';
    }
    else if (inform->zero_flag == 1)
    {
        while (i < inform->width - 1)
            res[i++] = '0';
        res[i++] = '%';
    }
    else
    {
        while (i < inform->width - 1)
            res[i++] = ' ';
        res[i++] = '%';
    }
    res[i] = '\0';
}

void    ft_write_percent(char **res, inform_list *inform)
{
    int i;

    i = 0;
    if (inform->width > 0)
    {
        (*res) = (char *)malloc(inform->width + 1);
        ft_write1_percent(*res, inform);
    }
    else
    {
        (*res) = (char *)malloc(2);
        (*res)[0] = '%';
        (*res)[1] = '\0';
    }
}

int     ft_percent_main(va_list ap,inform_list *inform, char *str)
{
    int i;
    char *res;

    i = 0;
    ft_init(inform);
    i = ft_side_write(str, i,inform) + 1;
    i = ft_flag(i, str, inform);
    ft_percent_setting(inform,ap,&str[i]);
    ft_write_percent(&res, inform);
    ft_write2(res, (size_t)ft_strlen(res,inform));
    inform->res_len += ft_strlen(res,inform);
    i = ft_forward(str, i);
    free(res);
    i = ft_side_write(str, i,inform);
    return(inform->res_len);    
}