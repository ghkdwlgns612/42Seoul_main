#include <stdio.h>
#include <string.h>

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	i = 0;
	s_len = strlen(src);
	d_len = strlen(dest);
	while (src[i] != 0 && d_len + i < size - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = 0;
	if (d_len < size)
		return (d_len + s_len);
	return (size + s_len);
}

int	main()
{
	char str1[] = "abcde";
	char str2[] = "xxxx";
	int num;
	num = ft_strlcat(str1, str2, 4);
	printf("%s\n%d\n",str1, num);
	return 0;
}
