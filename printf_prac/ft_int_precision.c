#include "ft_printf.h"

void    ft_dot_flag(inform_list *inform)
{
        if (inform->num > 0  && inform->dot == 1)
        {
            if (inform->dot_num < ft_int_length(inform->num))
            {
                inform->flag = 3;
                inform->width = inform->length;
            }
            else
                inform->flag = 1;
        }
        else if (inform->num < 0  && inform->dot == 1)
        {
            if (inform->dot_num < ft_int_length(-inform->num) + 1)
            {
                inform->flag = 3;
                inform->width = inform->length;
            }
            else
            {
                inform->flag = 1;
                inform->width += 1;
            }
        }
        else if (inform->num == 0  && inform->dot == 1)
            inform->flag = 1;
}

void    ft_dot(inform_list *inform, char *buf)
{
    while (*buf)
    {
        if (*buf == '.')
        {
            inform->dot = 1;
            buf++;
            while (*buf >= '0' && *buf <= '9')
            {
                inform->dot_num *= 10;
                inform->dot_num += *buf - '0';
                buf++;
            }
            if (*buf == '*')
                inform->flag = 1;
            ft_dot_flag(inform);
        }
        buf++;
    }
}