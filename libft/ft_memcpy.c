void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t i;
	char *dest_cpy;
	char *src_cpy;

	i = 0;
	dest_cpy = dest;
	src_cpy = src;
	if (dest_cpy == src_cpy)
		return (dest_cpy);
	while (i < num)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest_cpy);
}
