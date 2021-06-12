#include "ft_printf.h"

void    ft_char_setting(inform_list *inform, va_list ap, char *buf)
{
    inform->width = ft_width(buf, ap, inform);
    inform->precision = ft_precision(buf, ap, inform);
    inform->alpha = (char)(va_arg(ap,int));
    if (inform->width < 0)
            inform->width *= -1;
}

void    ft_char_input(char *res, inform_list *inform)
{
    int i;

    i = 0;
    if (inform->minus_flag == 1)
    {
        res[i++] = inform->alpha;
        while (i < inform->width)
            res[i++] = ' ';
    }
    else if (inform->width > 0)
    {
        while (i < inform->width - 1)
            res[i++] = ' ';
        res[i++] = inform->alpha;
    }
    else
        res[i++] = inform->alpha;
    res[i] = '\0';
}

int    ft_char_main(va_list ap, inform_list *inform, char *buf)
{
    char *res;
    int i;
    int j;

    j = 0;
    i = 0;
    ft_init(inform);
    i = ft_side_write(buf, i,inform) + 1;
    i = ft_flag(i, buf, inform);
    ft_char_setting(inform,ap,&buf[i]);
            // printf("width : %d\n", inform->width);
        // printf("preci : %d\n", inform->precision);
        // printf("num : %d\n", inform->num);
        // printf("length : %d\n", inform->num_len);
        // printf("dot : %d\n", inform->is_dot);
        // printf("zero : %d\n", inform->zero_flag);
        // printf("minus : %d\n", inform->minus_flag);
    if (inform->width > 0)
        res = (char *)malloc(inform->width + 1);
    else
        res = (char *)malloc(2);
    ft_char_input(res,inform);
    if (inform->width > 0)
        while (j < inform->width)
            write(1,&res[j++],1);
    else
        write(1,&res[0],1);
    inform->res_len += ft_strlen(res,inform);
    i = ft_forward(buf, i);
    free(res);
    i = ft_side_write(buf, i,inform);
    return(inform->res_len);
}