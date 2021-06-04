#inlcl

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
    char *str1;
    int i = 0;
    int arg;
    char *buf = ft_strdup(str);
    inform_list abc;
    
    va_start(ap,str);
    while (*buf)
    {
        if (*buf == '%' && *(buf + 1) != '\0')
        {
//            str1 = ft_buffer(buf, ap);
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
            if (*buf == 'd')
                abc.num = va_arg(ap, int);
            else if (*buf == 's')
                abc.str = va_arg(ap, char *);
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
   ft_printf("[  %0*s123156]","123133");
//    printf("%*s",-5 ,"123");
    return 0;
}
