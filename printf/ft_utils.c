#include "ft_printf.h"

void    ft_write(char *str)
{
    while (*str)
        write(1,str++,1);
    write(1,"\n",1);
}

int	ft_strlen(char *str)
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


int     ft_int_length(int num)
{
    int cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }
    return (cnt);
}