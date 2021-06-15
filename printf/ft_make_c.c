#include "ft_printf.h"

void	c_noflag(t_format *t_node, char c)
{
	int i;
	int size;

	i = 0;
	size = t_node->size;
	while (size + i < t_node->wid)
	{
		t_node->result[i++] = ' ';
	}
	t_node->result[i++] = c;
}

void	c_flag_minus(t_format *t_node, char c)
{
	int i;

	i = 0;
	t_node->result[i++] = c;
	while (i < t_node->wid)
		t_node->result[i++] = ' ';
}

void	c_flag_zero(t_format *t_node, char c)
{
	int i;
	int size;

	i = 0;
	size = t_node->size;
	if (t_node->flag[2] == 1)
	{
		if (t_node->prec < t_node->size)
			size = t_node->prec;
	}
	while (size + i < t_node->wid)
	{
		t_node->result[i++] = '0';
	}
	t_node->result[i++] = c;
}
