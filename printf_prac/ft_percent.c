#include "ft_printf.h"

int     ft_percent_main(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (str[i] != '\0' && str[i] != '%')
    {
        write(1,&str[i++],1);
        len++;
    }
    i++;
    len++;
    write(1,"%",1);
    while (str[i] != '\0' && str[i] != '%')
        i++;
    i++;
    while (str[i] != '\0' && str[i] != '%')
    {
        write(1,&str[i++],1);
        len++;
    }
    return (len);
}