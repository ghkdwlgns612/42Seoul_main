#include "ft_printf.h"

void    ft_type(inform_list *inform, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == 'd')
            inform->type = 1;
        else if (str[i] == 'c')
            inform->type = 2;
        else if (str[i] == 's')
            inform->type = 3;
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