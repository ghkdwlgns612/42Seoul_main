void	ft_bzero(void *ptr, size_t size)
{
	int		i;
	unsigned char	*startptr;

	startptr = (unsigned char *)ptr;
	i = 0;
	while (size--)
		startptr[i++] = 0;
}
