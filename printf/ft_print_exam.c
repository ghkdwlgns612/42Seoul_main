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

char    *ft_forward(char *str)
{
    char *buf;
    
    buf = ft_strdup(str);
    while (*buf != '\0' && *buf != '%')
        buf++;
    return (buf);
}

int     ft_zero_minus(char *str)
{
    if ()
        if ((*str == '0' && *(str + 1) == '-') && (*str == '-' && *(str + 1) == '0'))
        {
            ft_start_left();
        }
        else if ()
    return (1);
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    inform_list inform;
    int result_cnt = 0;
    char *buf;
    int len;
    
    buf = ft_strdup(str);
    va_start(ap,str);
    while (*buf)
    {
        if (*buf == '%')
        {
            buf++;
            arg = va_arg(ap,ft_select_type(*(buf - 1)));
            while (*buf != '%' || *buf != '\0')
            {
                if (*buf == '0' || *buf == '-' || (*buf == '0' && *(buf + 1) == '-') || (*buf == '-' && *(buf + 1) == '0')) 
                {
                    result_cnt = ft_zero_minus(buf);
                    buf = ft_forward(buf);
                }
                else if (*buf == '*')
                {
//                    result_cnt = ft_star_width(buf);
                    buf = ft_forward(buf);
                }
                else if (*buf == '.')
                {
 //                   result_cnt = ft_precision(buf);
                    buf = ft_forward(buf);
                }
                else if (*buf >= '1' && *buf <= '9')
                {
 //                   result_cnt = ft_width();
                    buf = ft_forward(buf);
                }
                else if (*buf == 'a')
                {
 //                   result_cnt = ft_print_case();
                    buf = ft_forward(buf);
                }
                else
                    break ;
            }
        }
        else
        {
            write(1,buf++,1);
        }
    }
    return (result_cnt);
}

int     main()
{
    ft_printf("  %0 312312","123");
//    printf("%05  d",1234);
    return 0;
}
