#include "ft_printf.h"

void    ft_num_value(char *res,inform_list *inform)
{
    int temp;
    int len;
  
    temp = inform->num;
    len = inform->num_len;
    if (temp < 0)
    {
        temp *= -1;
        len++;
    }
    res[len--] = '\0';
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;
    }
    if (len == 0 && inform->num < 0)
        res[0] = '-';
}


void    ft_precision_value(char *res,inform_list *inform) //25줄 애매
{
    int temp;
    int gap;
    int len;

    gap = inform->precision - inform->num_len; 
    if (inform->num < 0)
    {
        temp = inform->num * (-1);
        len = inform->precision + 1;
        res[0] = '-';
    }
    else
    {
        temp = inform->num;
        len = inform->precision;
    }
    res[len--] = '\0';
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;        
    }
    while (gap--)
        res[len--] = '0';
}

void    ft_ignore_zero(char **res,inform_list *inform) //수정 필요.
{
    if ((inform->width > inform->precision && inform->precision > inform->num_len) || (inform->width > inform->precision && inform->width > inform->num_len)) //width할당, -플래그 확인, pre적용 후, 양음확인 or width할당, -플래그 확인, pre미적용, 양음확인
    {
        *res = (char *)malloc(inform->width + 1);
        if (inform->minus_flag == 1)
        {
            if (inform->num < 0)
                ft_left_precision_value(*res, inform, inform->num_len + 1);
            else
                ft_left_precision_value(*res, inform, inform->num_len);    
        }
        else
            ft_right_precision_value(*res, inform, inform->width);
    }
    else if (inform->precision > inform->num_len && inform->precision >= inform->width) //pre할당 후 양음 확인 바로 값넣기.
    {
        if (inform->num < 0)
            *res = (char *)malloc(inform->precision + 2);
        else
            *res = (char *)malloc(inform->precision + 1);   
        ft_precision_value(*res, inform);    
    }
    else //num_len 할당 후 양음 확인 후 바로 값 넣기.
    {
        if (inform->num >= 0)
            *res = (char *)malloc(inform->num_len + 1);
        else
            *res = (char *)malloc(inform->num_len + 2);
        ft_num_value(*res, inform);
    }
}

void    ft_zero_value(char *res, inform_list *inform)
{
    int len;
    int temp;

    temp = inform->num;
    len = inform->width;
    if (inform->num < 0)
        temp *= -1;
    res[len--] = '\0';
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;        
    }
    while (len)
        res[len--] = '0';
    if (inform->num < 0)
        res[len] = '-';
    else
        res[len] = '0';
}

void    ft_zero_minus(char **res,inform_list *inform) //24줄 애매
{
    if (inform->width > inform->num_len)
    {
        *res = (char *)malloc(inform->width + 1);
        if (inform->minus_flag == 1)
        {
            if (inform->num < 0)
                ft_left_precision_value(*res, inform, inform->num_len + 1);
            else
                ft_left_precision_value(*res, inform, inform->num_len); 
        }
        else if (inform->zero_flag == 1)
            ft_zero_value(*res,inform);
        else
            ft_right_precision_value(*res, inform, inform->width);
    }
    else
    {
        if (inform->num >= 0)
            *res = (char *)malloc(inform->num_len + 1);
        else
            *res = (char *)malloc(inform->num_len + 2);
        ft_num_value(*res, inform);
    }
}