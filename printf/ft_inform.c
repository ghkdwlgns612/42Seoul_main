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
        // case 2 :
        //     inform->str = va_arg(ap,char *);
        //     inform->length = 1;
        //     break;
        // case 3 :
        //     inform->str = va_arg(ap,char *);
        //     inform->length = ft_strlen(inform->str);
        //     break;
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
        inform->flag = 2; //왼쪽 정렬
    else if (buf[i] == '0')
        inform->flag = 1; //- 채우기
    else
        inform->flag = 3; //아무 플래그 없음
}

void    ft_width(inform_list *inform, char *buf, va_list ap)
{
    int i = 0;
    while (buf[i])
    {
        if (inform->dot == 1)
        {
            inform->width = inform->dot_num + 1;
            break ;
        }
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
        buf++;
    }
}