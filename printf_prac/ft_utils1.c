#include "ft_printf.h"

int     ft_int_length(int num)
{
    int cnt;

    cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }
    return (cnt);
}

int     ft_strlen(const char *str)
{
	int     i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void    ft_write(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1,&str[i++],1);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (minus * res);
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