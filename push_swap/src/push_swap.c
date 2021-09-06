#include "../push.h"

int				ft_minus(char c)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			return (-1);
	}
	return (1);
}

long long				ft_atoi(const char *str)
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


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
    return (i);
}


int ft_check_arg(const char *str) { //str -> 부호 제외하고 10자리인지 확인 -> long long변환 후 int_max , int_min랑 확인
    int i = 0;
    int len = ft_strlen(str);
    //숫자로 사용될수있는지 확인(1234, -1234, 12-34, 12a2, -12-12)
    while (str[i] != 0)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            if (!(i == 0 && str[i] == '-'))
            {
                printf("Error\n");
                exit(0);
            }
        }
        i++;
    }
    //정수범위내에 들어오는지 확인
    long long ret = ft_atoi(str);
    if (ret > 2147483647 || ret < -2147483648)
    {
        printf("Error\n");
        exit(0);
    }
    return (int)ret;
}


int main(int argc, char *argv[]) {
    int i = 1;
    int arr[argc - 1];
    while(i < argc)
        arr[i-1] = ft_check_arg(argv[i++]);
    return 0;
}