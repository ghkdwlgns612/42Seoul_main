#include <stdio.h>
#include <unistd.h>

void *ft_memset (void *ptr, int value, size_t num)
{
	size_t i;
	char *start_ptr;
	unsigned char data;

	start_ptr = (char *)ptr;
	data = (unsigned char)value;
	i = 0;
	while (num--)
	{
		start_ptr[i++] = data;
	}
	return ptr;
}
