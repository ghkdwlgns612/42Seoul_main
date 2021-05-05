char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	printf("%p\n",&big[i]);
	if (*little == 0)
		return ((char *)&big[0]);
	while(i < len && big[i] != 0)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && little[j] != 0)
				j++;
			if (little[j] == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	printf("%p\n",&big[i]);
	return (0);
}
