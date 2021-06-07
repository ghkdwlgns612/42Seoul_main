#include "ft_printf.h"

void    ft_init(inform_list *inform)
{
    inform->cnt = 0;
    inform->flag = 0;
    inform->length = 0;
    inform->num = 0;
    inform->result_cnt = 0;
    inform->type = 0;
    inform->width = 0;
    inform->dot = 0;
    inform->dot_num = 0;
}

void    ft_type(inform_list *inform, char *buf)
{
    int i = 0;

    while (buf[i] && (buf[i] != 'c' || buf[i] != 's' || buf[i] != 'd'))
        i++;
    if (buf[i - 2] == 'd')
        inform->type = 1;
    else if (buf[i - 2] == 'c')
        inform->type = 2;
    else if (buf[i - 2] == 's')
        inform->type = 3;
}

void    ft_length(inform_list *inform, char *buf, va_list ap)
{
    switch (inform->type)
    {
        case 1 :
            inform->num = va_arg(ap,int);
            if (inform->num < 0)
                inform->length = ft_int_length(-inform->num) + 1;
            else
                inform->length = ft_int_length(inform->num);
            break;
        default:
            break;
    }
}

void    ft_flag(inform_list *inform, char *buf)
{
    int i = 0;
    while(buf[i] && buf[i] != '%')
        i++;
    i++;
    if (buf[i] == '-' || (buf[i] == '-' && buf[i + 1] == '0') || (buf[i] == '0' && buf[i + 1] == '-'))
        inform->flag = 2;
    else if (buf[i] == '0')
        inform->flag = 1;
    else
        inform->flag = 3;
}

void    ft_width(inform_list *inform, char *buf, va_list ap)
{
    int i;

    i = 0;
    while (buf[i])
    {
        if (buf[i] == '*')
        {
            inform->width = va_arg(ap,int);
            break ;
        }
        else if (buf[i] >= '1' && buf[i] <= '9')
        {
            while (buf[i] >= '0' && buf[i] <= '9')
            {
                inform->width *= 10;
                inform->width += buf[i++] - '0';
            }
            break ;
        }
        i++;
    }
}