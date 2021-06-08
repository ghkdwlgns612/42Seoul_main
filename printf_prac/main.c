#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int     ft_star(va_list ap)
{
    return (va_arg(ap,int));
}

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


int     ft_chk_precision(char *str, va_list ap)
{
    int i;
    int num;

    num = 0;
    i = 0;
    while (str[i] != '\0' && str[i] != '%')
    {
        if (str[i] == '.')
        {
            i++;
            if (str[i] == '*')
                num = ft_star(ap);
            else if (str[i] > '0' && str[i] < '9')
            {
                while (str[i] > '0' && str[i] < '9')
                {
                    num *= 10;
                    num += str[i++] - '0';
                }
            }
            else
                num = 0;
        }
        i++;
    }
    return (num);
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    char *buf;
    int i;
    int precision_num;

    buf = ft_strdup(str);
    va_start(ap,str);
    i = 0;
    while (buf[i])
    {
        while (buf[i] != '%' && buf[i] != '\0')
            write(1,&buf[i++],1);
        i++;
        precision_num = ft_chk_precision(&buf[i], ap);
        printf("%d\n",precision_num);
        break ;
    }
    free(buf);
    return (1);
}

int main()
{
    ft_printf("%.*d",29);
}
