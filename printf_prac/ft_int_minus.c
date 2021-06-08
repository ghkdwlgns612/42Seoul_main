#include "ft_printf.h"

int    ft_minus_int_setting_printf(inform_list *inform, char *str)
{
    int len;

    len = 0;
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

void    ft_minus_int_flag_arr(inform_list *inform, int temp, int len, char *str)
{
      if (inform->flag == 1)
            while (len > -1)
            {
                if (temp != 0)
                {
                    str[len--] = (temp % 10) + '0';
                    temp /= 10;
                }
                else if (temp == 0 && len == 0)
                    str[len--] = '-';
                else
                    str[len--] = '0';
            }
        else if(inform->flag == 2)
        {
            str[--len] = '\0';
            len--;
            while (temp && len != 0)
            {
                if (temp != 0)
                {
                    str[len--] = (temp % 10) + '0';
                    temp /= 10;
                    if (len == 0)
                        str[len] = '-';
                }
            }
        }
}

void    ft_minus_int_put_value(inform_list *inform, int temp, int len, char *str)
{
    if (inform->flag == 1)
        ft_minus_int_flag_arr(inform,temp,len,str);
    else if (inform->flag == 2)
        ft_minus_int_flag_arr(inform,temp,len,str);
    else if (inform->flag == 3)
    {
        while (temp)
        {
            str[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        str[len--] = '-';
        while (len > -1)
            str[len--] = ' ';
    }
}

int    ft_minus_int_print(inform_list *inform, char *str)
{
    int temp = (inform->num) * (-1);
    int len;

    if (inform->flag == 3)
    {
        len = ft_minus_int_setting_printf(inform,str);
        ft_minus_int_put_value(inform,temp,len,str);
    }
    else if (inform->flag == 2)
    {
        len = ft_minus_int_setting_printf(inform,str) + 2;
        ft_minus_int_put_value(inform,temp,len,str);
    }
    else if (inform->flag == 1)
    {
        len = ft_minus_int_setting_printf(inform,str);
        ft_minus_int_put_value(inform,temp,len,str);
    }
    len = ft_res_strlen(inform, str);
    ft_write(str);
    return(len);
}