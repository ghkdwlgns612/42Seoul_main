#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (minus * res);
}

int	main()
{
	printf("%d\n",ft_atoi("  -1234"));
	printf("%d\n",ft_atoi("		234"));
	printf("%d\n",ft_atoi("- 12345"));
	return 0;
}
