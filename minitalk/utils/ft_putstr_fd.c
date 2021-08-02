#include "utils.h"

int		ft_putstr_fd(char *s, int fd)
{
	int len;

	if (!s || fd < 0)
		return (-1);
	len = ft_strlen(s);
	len = write(fd, s, len);
	return (len);
}