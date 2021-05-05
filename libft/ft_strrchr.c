#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	int	i;
	const	char *str;

	i = 0;
	str = 0;
	while (s[i])
	{
		if (s[i] == (char)ch)
			str = &s[i];
		i++;
	}
	if (ch == 0)
		return ((char *)&s[i]);
	return ((char *)str);
}
