#include <stdio.h>

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t 	i;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dest == 0 || src == 0)
		return 0;
	while (src[i] != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

int	main()
{
	char str1[] = "abcdefg";
	char str2[] = "xxx";
	int size;

	size = ft_strlcpy(str1, str2, 7);
	printf("%s\n%d\n",str1, size);

	return 0;
}
