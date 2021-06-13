#include "ft_printf.h"

void    ft_str_setting(inform_list *inform, va_list ap, char *buf)
{
    inform->width = ft_width(buf, ap, inform);
    inform->precision = ft_precision(buf, ap, inform);
    inform->str = va_arg(ap,char *);
    if (inform->width < 0)
            inform->width *= -1;
}

void    ft_str_input(char *res, inform_list *inform)
{
    int i;
    int j;
    char *str;

    str = ft_strdup(inform->str);
    i = 0;
    j = 0;
    if (inform->minus_flag == 1)
    {
        while (str[i])
            res[i++] = str[i];
        while (i < inform->width)
            res[i++] = ' ';
    }
    else if (inform->width > 0)
    {
        while (i < inform->width - ft_strlen(str,inform))
            res[i++] = ' ';
        while (str[j])
            res[i++] = str[j++];
    }
    res[i] = '\0';
}

int    ft_str_main(va_list ap, inform_list *inform, char *buf)
{
    char *res;
    int i;

    i = 0;
    ft_init(inform);
    i = ft_side_write(buf, i,inform) + 1;
    i = ft_flag(i, buf, inform);
    ft_str_setting(inform,ap,&buf[i]);
    if (inform->width > 0)
        res = (char *)malloc(inform->width + 1);
    else
        res = (char *)malloc(2);
    ft_str_input(res,inform);
    ft_write(res, (size_t)ft_strlen(res,inform));
    inform->res_len += ft_strlen(res,inform);
    i = ft_forward(buf, i);
    free(res);
    i = ft_side_write(buf, i,inform);
    return(inform->res_len);
}
