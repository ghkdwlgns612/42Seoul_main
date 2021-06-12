#include "ft_printf.h"
//5개
void    ft_left_zero_value(char *res, inform_list *inform)
{
    int i;

    i = 0;
    if (inform->precision == 0 && inform->is_dot == 0)
        res[i++] = '0';
    while (i < inform->precision)
        res[i++] = '0';
    while (i < inform->width)
        res[i++] = ' ';
    res[i] = '\0';
}

void    ft_right_zero_value(char *res, inform_list *inform)
{
    int i;
    int cnt;

    i = inform->width;
    cnt = 0;
    res[i--] = '\0';
    if (inform->precision == 0 && inform->is_dot == 0)
        res[i--] = '0';
    while (cnt < inform->precision)
    {
        res[i--] = '0';
        cnt++;
    }
    while (i > -1)
        res[i--] = ' ';
}

void    ft_precision_zero_value(char *res, inform_list *inform)
{
    int i;

    i = 0;
    while (i < inform->precision)
        res[i++] = '0';
    res[i] = '\0';
}

void    ft_zero_except_print(inform_list *inform, char *res)
{
    if (inform->precision == 0 && inform->width == 0 && inform->is_dot == 0)
    {
        res[0] = '0';
        res[1] = '\0';            
    }
    else
        res[0] = '\0';
}

void    ft_zero_printf(char **res, inform_list *inform) //24줄 애매
{
    if (inform->width && inform->width > inform->precision)
    {
        *res = (char *)malloc(inform->width + 1);
        if (inform->minus_flag == 1)
            ft_left_zero_value(*res,inform);
        else if (inform->zero_flag == 1 && inform->is_dot == 0)
            ft_zero_value(*res,inform);
        else
            ft_right_zero_value(*res,inform);
    }
    else if (inform->precision && inform->precision >= inform->width)
    {
        *res = (char *)malloc(inform->precision + 1);
        ft_precision_zero_value(*res,inform);
    }
    else
    {
        if (inform->precision == 0 && inform->width == 0 && inform->is_dot == 0)
            *res = (char *)malloc(2);
        else
            *res = (char *)malloc(1);
        ft_zero_except_print(inform,*res);            
    }
}