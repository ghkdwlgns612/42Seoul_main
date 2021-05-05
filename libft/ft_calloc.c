void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (ret == 0)
		return (0);
	ft_memset(ret, 0, size * count);
	return (ret);
}
