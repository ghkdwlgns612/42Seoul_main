#include "ft_printf.h"

int    ft_int_setting_printf(inform_list *inform, char *str)
{
    int len;

    if (inform->flag == 1)
    {
        len = inform->width;
        str[len--] = '\0';
    }
    else if (inform->flag == 2)
    {
        len = inform->length;
        str[len--] = '\0';
    }
    else if (inform->flag == 3)
    {
        
        if (inform->width != 0)
            len = inform->width;
        else
            len = ft_int_length(inform->num);
        str[len--] = '\0';
    }
    return (len);
}

void    ft_int_flag_arr(inform_list *inform, int temp, int len, char *str)
{
        if (inform->flag == 1)
            while (len > -1)
            {
                if (temp != 0)
                {
                    str[len--] = (temp % 10) + '0';
                    temp /= 10;
                }
                else
                    str[len--] = '0';
            }
        else if(inform->flag == 2)
        {
            str[len--] = '\0';
            while (temp)
            {
                if (temp != 0)
                {
                    str[len--] = (temp % 10) + '0';
                    temp /= 10;
                }
            }
        }
}

void    ft_int_put_value(inform_list *inform, int temp, int len, char *str)
{
    if (inform->flag == 1)
        ft_int_flag_arr(inform,temp,len,str);
    else if (inform->flag == 2)
        ft_int_flag_arr(inform,temp,len,str);
    else if (inform->flag == 3)
    {
        while (temp)
        {
            str[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        while (len > -1)
            str[len--] = ' ';
    }
}