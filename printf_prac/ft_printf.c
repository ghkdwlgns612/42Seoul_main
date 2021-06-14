#include "ft_printf.h"

void    ft_type_inner(inform_list *inform, char alpha)
{
    int i;

    i = 0;
    if (alpha == 'd' || alpha == 'i' || alpha == 'u')
    {
        if (alpha == 'u')
            inform->unsigned_flag == 1;
        inform->type = 1;
    }
    else if (alpha == 'c')
        inform->type = 2;
    else if (alpha == 's')
        inform->type = 3;
    else if (alpha == 'p')
        inform->type = 4;
    else if (alpha == 'x' || alpha == 'X')
        inform->type = 5;
    else if (alpha == '%')
        inform->type = 6;
}

void    ft_type(inform_list *inform, char *str)
{
    int i;

    i = 0;
    inform->unsigned_flag = 0;
    while (str[i])
    {
        ft_type_inner(inform, str[i]);
        i++;
    }
}

int    ft_select(inform_list *inform, va_list ap, char *str)
{
    ft_type(inform,str);
    if (inform->type == 1)
        return (ft_int_main(ap,inform,str));
    else if (inform->type == 2)
        return (ft_char_main(ap,inform,str));
    else if (inform->type == 3)
        return (ft_str_main(ap,inform,str));
    else if (inform->type == 4)
        return (ft_pointer_main(ap,inform,str));
    // else if (inform->type == 5)
    //     return (ft_hex_main());
    else if (inform->type == 6)
        return (ft_percent_main(str));
    else
        return (ft_int_main(ap,inform,str));   
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    inform_list *inform;
    char *buf;
    int result;

    buf = ft_strdup(str);
    inform = (inform_list *)(malloc)(sizeof(inform_list));
    va_start(ap,str);
    result = ft_select(inform,ap,buf);
    va_end(ap);
    free(inform);
    free(buf);
    return (result);
}

int main()
{
    void *integer = 1234;
    printf("|%5.5p|\n",integer);
    // ft_printf("|%9p|\n",integer);
    return (0);
}