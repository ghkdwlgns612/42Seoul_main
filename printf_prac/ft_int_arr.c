#include "ft_printf.h"

void    ft_left_precision_value_apt(char *res, inform_list *inform, int r_len)
{
    int temp;
    int len;

    len = r_len - 1;
    temp = inform->num;
    if (temp < 0)
        temp *= -1;
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;
    }
    while (len > -1)
    {
        if (len == 0 && inform->num < 0)
            res[len--] = '-';
        else
            res[len--] = '0';
    }
    len = r_len;
    while (len < inform->width)
        res[len++] = ' ';
    res[len] = '\0';
}

void    ft_left_precision_value(char *res, inform_list *inform, int r_len)
{
    int temp;
    int len;
    int gap;

    gap = inform->precision - inform->num_len;
    len = r_len;
    temp = inform->num;
    if (temp < 0)
        temp *= -1;
    if (inform->precision > inform->num_len) //오른쪽 정렬인데 pre존재. 양음 확인필요.
        ft_left_precision_value_apt(res, inform, len + gap); //len + gap부터 숫자 넣기. >001234    <
    else //오른쪽 정렬인데 pre 존재 x. 양음 확인.
    {
        len--;
        while (temp)
        {
            res[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        if (inform->num < 0)
            res[len--] = '-';
        len = r_len;
        if (inform->num < 0)
            while (len < inform->width)
                res[len++] = ' ';
        else
            while (len < inform->width)
                res[len++] = ' ';   
        res[len] = '\0';        
    }
}

void    ft_right_precision_value_apt(char *res, inform_list *inform, int gap)
{
    int temp;
    int len;
    int zero;

    zero = gap;
    len = inform->width - 1;
    temp = inform->num;
    if (temp < 0)
        temp *= -1;
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;
    }
    while (zero--)
        res[len--] = '0';
    if (inform->num < 0)
        res[len--] = '-';
    while (len > -1)
        res[len--] = ' ';   
}

void    ft_right_precision_value(char *res, inform_list *inform, int r_len)
{
    int temp;
    int len;
    int gap;

    gap = inform->precision - inform->num_len;
    len = r_len;
    temp = inform->num;
    if (temp < 0)
        temp *= -1;
    res[len--] = '\0';
    if (inform->precision > inform->num_len) //오른쪽 정렬인데 pre존재. 양음 확인필요.
        ft_right_precision_value_apt(res, inform, gap);//inform->width에서 시작해서 gap만큼 '0'넣고 ' '넣기.
    else //오른쪽 정렬인데 pre 존재 x. 양음 확인.
    {
        while (temp)
        {
            res[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        if (inform->num < 0)
            res[len--] = '-';
        while (len > -1)
            res[len--] = ' ';        
    }
}
