#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			size;
	t_format	*t_node;

	t_node = (t_format*)malloc(sizeof(t_format));
	va_start(t_node->ap, format);
	init_firstnode(t_node, (char *)format);
	start_printf(t_node);
	if (t_node->spec == '0')
	{
		va_end(t_node->ap);
		free(t_node);
		return (-1);
	}
	va_end(t_node->ap);
	size = t_node->nums;
	free(t_node);
	return (size);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(t_format *t_node)
{
	int i;

	i = 0;
	if (t_node->spec == 'c' && t_node->num[0] == '\0')
	{
		printf("%s",t_node->num);
		while (i < t_node->max_size)
		{
			write(1, &t_node->result[i], 1);
			i++;
		}
		t_node->nums += t_node->max_size;
		return ;
	}
	while (t_node->result[i] != 0)
	{
		write(1, &t_node->result[i], 1);
		i++;
	}
	t_node->nums += pf_strlen(t_node->result);
}


int		main()
{
	ft_printf("%4c\n",'A');
	return 0;
}