#include <stdio.h>

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return((char *)&str[i]);
		i++;
	}
	if (ch == 0)
		return ((char *)&str[i]);
	return (0);
}

int	main()
{
	char str[] = "abcdef";
	char *str_cp;
	str_cp = ft_strchr(str, 98);
	printf("%s\n",str_cp);
	return 0;
}
