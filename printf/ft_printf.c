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


void    ft_print011(char *res, void *data, char *str)
{
    int mod = 0;
    int i;
    int len;
    int temp;
    
    if (str == "int")
    {
        temp = data;
        while (temp)
        {
            temp /= 10;
            len++;
        }
        res[len--] = '\0';
        while (len)
        {
            mod = data % 10;
            res[len--] = mod;
        }
    }
    else
    {}
}


char    *ft_write(char *res, char *type, void *data, char *str)
{
    if (type[0] == '1' && type[1] == '1' && type[2] == '1')
        ft_print011(res,data,str);
    else if (type[0] == '1' && type[1] == '1' && type[2] == '0')
        ft_print011(res,data,str);
    else if (type[0] == '1' && type[1] == '0' && type[2] == '0')
        ft_print011(res,data,str);
    else if (type[0] == '1' && type[1] == '0' && type[2] == '1')
        ft_print011(res,data,str);
    else if (type[0] == '0' && type[1] == '1' && type[2] == '1')
        ft_print011(res,data,str);
    else if (type[0] == '0' && type[1] == '0' && type[2] == '1')
        ft_print011(res,data,str);
    else if (type[0] == '0' && type[1] == '1' && type[2] == '0')
        ft_print011(res,data,str);
    else if (type[0] == '0' && type[1] == '0' && type[2] == '0')
        ft_print011(res,data,str);
    return (res);
}


int     ft_width(char *str)
{
    int num = 0;
    
    while (*str >= '1' && *str <= '9')
    {
        num *= 10;
        num += *str - '0';
        str++;
    }
    return (num);
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
            while (*buf && *buf != 'c'&& *buf != 's'&& *buf != 'p'&& *buf != 'd'&& *buf != 'i'&& *buf != 'u'&& *buf != 'x'&& *buf != 'X')
            {
                if (*buf == '*')
                    type[0] = '1';
                else if(*buf == '-')
                    type[1] = '1';
                else if(*buf == '0')
                    type[2] = '1';
                else if(*buf >= '1' && *buf <= '9')
                {
                    len = ft_width(buf);
                    while (*buf >= '1' && *buf <= '9')
                        buf++;
                }
                else
                    write(1,&(*buf),1);
                buf++;
            }
            if (*buf == 'd') //int형
            {
                abc.num = va_arg(ap, int);
                temp = abc.num;
                if (len == 0)
                {
                    while (temp)
                    {
                        temp /= 10;
                        len++;
                    }
                }
                res = (char *)malloc(sizeof(char) *(len + 1));
                res = ft_write(res,type,&abc.num, "int");
            }
            else if (*buf == 's') // str형
            {
                abc.str = va_arg(ap, char *);
                if (len == 0)
                    len = ft_strlen(abc.str);
                res = (char *)malloc(sizeof(char) *(len + 1));
                res = ft_write(res,type,abc.str,"str");
            }
            if (*buf == 's' || *buf == 'd')
                free(res);
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
    return (len);
}



int main()
{
//    ft_printf("[  %0-s123156]", "1234");
    int num;
    num = printf("%-5\n","123");
    printf("num : %d\n",num);
    return 0;
}

