#include "ft_printf.h"

int     ft_star_precision(va_list ap, inform_list *inform)
{
    int num;

    num = va_arg(ap,int);
    if (num < 0)
    { 
        inform->is_dot = 0;
        return (0);
    }
    else 
        return (num);
}

int     ft_star_width(va_list ap,inform_list *inform)
{
    int num;

    num = va_arg(ap,int);
    if (num < 0)
    {
        inform->minus_flag = 1;
        return (-num);
    }
    else 
        return (num);
}

int     ft_flag(int i, char *str,inform_list *inform)
{
    if ((str[i] == '0' && str[i + 1] == '-') || (str[i] == '0' && str[i + 1] == '-'))
    {
        inform->zero_flag = 1;
        inform->minus_flag = 1;
        return (i + 2);
    }
    else if (str[i] == '0')
    {
        inform->zero_flag = 1;
        return (i + 1);
    }
    else if (str[i] == '-')
    {
        inform->minus_flag = 1;
        return (i + 1);
    }
    else
    {
        return (i);
    }    
}

int     ft_precision(char *str, va_list ap, inform_list *inform) //수정 필요.
{
    int i;
    int num;
    
    num = 0;
    i = 0;
    while (str[i] != '\0' && str[i] != '%')
    {
        if (str[i] == '.')
        {
            inform->is_dot = 1;
            i++;
            if (str[i] == '*')
            {
                num = ft_star_precision(ap,inform);
                break ;
            }
            else if (str[i] == '-' || (str[i] > '0' && str[i] < '9'))
            {
                num = ft_atoi(&str[i]);
                break ;
            }
            else
                num = -1;
        }
        i++;
    }
    return (num);
}

int     ft_width(char *str, va_list ap, inform_list *inform)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (str[i] != '\0' && str[i] != '%' && str[i] != '.')
    {
        if (str[i] == '*')
        {
            num = ft_star_width(ap,inform);
            break ;
        }
        else if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
        {
            num = ft_atoi(&str[i]);
            break ;
        }
        else
            num = -1;
        i++;
    }
    return(num);
}
