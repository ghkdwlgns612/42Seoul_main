#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = 0;
	while (str[len])
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}


char     *ft_buffer(char *buf, va_list ap)
{
    char ret;

    while (1)
    {
        if (*buf == 'c' ||*buf == 's' ||*buf == 'p' ||*buf == 'd' ||*buf == 'i' ||*buf == 'u' ||*buf == 'x' ||*buf == 'X')
            break;
        else
        {
            ft_flag(*buf,)
        }
        buf++;
    }
    ft_result()
    ret = *buf;
    buf++;

    
    if (ret == 'c')
        return ("char");
    else if (ret == 's')
    {}   
    else if (ret == 'p')
    {}
    else if (ret == 'd')
        return ("int");
    else if (ret == 'i')
    {}
    else if (ret == 'u')
    {}
    else if (ret == 'x')
    {}
    else if (ret == 'X')
    {}
}


int     ft_printf(const char *str, ...)
{
    va_list ap;
    char *type;
    int i = 0;
    char *buf = ft_strdup(str);
    
    va_start(ap,str);
    while (*buf)
    {
        if (*buf == '%' && *(buf + 1) != '\0')
        {
            type = ft_buffer(buf, ap);
            while (*buf && *buf != 'c'&& *buf != 's'&& *buf != 'p'&& *buf != 'd'&& *buf != 'i'&& *buf != 'u'&& *buf != 'x'&& *buf != 'X')
                buf++;
            if (*(buf + 1) != '\0')
                buf++;
        }
        else if(*buf != '%')
        {
           write(1,buf,1);
           printf("\n");
        }
        buf++;
    }
    va_end(ap);
    return (i);
}



int main()
{
    ft_printf("[  %0+-d123156%s]",123,"asd");
    return 0;
}

