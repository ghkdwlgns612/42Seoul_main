#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct inform {
    int num;
    char alpha;
    char *str;
    double dot;
}   inform_list;

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
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


void    ft_print111(char *res)
{
}


char    *ft_write(char *res, char *type, void *data)
{
    if (type[0] == '1' && type[1] == '1' && type[2] == '1')
        ft_print111(res);
    else if (type[0] == '1' && type[1] == '1' && type[2] == '0')
        ft_print110(res);
    else if (type[0] == '1' && type[1] == '0' && type[2] == '0')
        ft_print100(res);
    else if (type[0] == '1' && type[1] == '0' && type[2] == '1')
        ft_print101(res);
    else if (type[0] == '0' && type[1] == '1' && type[2] == '1')
        ft_print011(res);
    else if (type[0] == '0' && type[1] == '0' && type[2] == '1')
        ft_print001(res);
    else if (type[0] == '0' && type[1] == '1' && type[2] == '0')
        ft_print010(res);
    else if (type[0] == '0' && type[1] == '0' && type[2] == '0')
        ft_print000(res);
    printf("%s\n",res);
    return (res);
}


char     *ft_buffer(char *buf, va_list ap)
{
    char ret;
    int len;
    
    len = 0;
    while (1)
    {
        if (*buf == 'c' ||*buf == 's' ||*buf == 'p' ||*buf == 'd' ||*buf == 'i' ||*buf == 'u' ||*buf == 'x' ||*buf == 'X')
            break;
        else
        {
        }
        buf++;
    }
    ret = *buf;
    buf++;
}


int     ft_printf(const char *str, ...)
{
    va_list ap;
    char type[3] = {'0','0','0'};
    char *res;
    int i = 0;
    int len = 0;
    int temp = 0;
    char *buf = ft_strdup(str);
    inform_list abc;
    
    va_start(ap,str);
    while (*buf)
    {
        if (*buf == '%' && *(buf + 1) != '\0')
        {
            str1 = ft_buffer(buf, ap);
            while (*buf && *buf != 'c'&& *buf != 's'&& *buf != 'p'&& *buf != 'd'&& *buf != 'i'&& *buf != 'u'&& *buf != 'x'&& *buf != 'X')
            {
                if (*buf == '0')
                    type[0] = '1';
                else if(*buf == '-')
                    type[1] = '1';
                else if(*buf == '*')
                    type[2] = '1';
                buf++;
            }
            if (*buf == 'd') //int형
            {
                abc.num = va_arg(ap, int);
                temp = abc.num;
                while (temp)
                {
                    temp /= 10;
                    len++;
                }
                res = (char *)malloc(sizeof(char) *(len + 1));
                res = ft_write(res,type);
            }
            else if (*buf == 's') // str형
            {
                abc.str = va_arg(ap, char *);
                len = ft_strlen(abc.str);
                res = (char *)malloc(sizeof(char) *(len + 1));
                res = ft_write(res,type);
            }
            printf("res : %s\n",res);
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
   ft_printf("[  %0*s123156]", "1234");
//    printf("%*s",-5 ,"123");
    return 0;
}
