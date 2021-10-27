#include "../../so_long.h"

static	int	num_len(int n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*new;
	long	num;

	num = n;
	len = num_len(num);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (num < 0)
	{
		new[0] = '-';
		num = -num;
	}
	if (num == 0)
		new[0] = '0';
	new[len] = 0;
	while (num)
	{
		new[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (new);
}
