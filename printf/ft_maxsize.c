#include "ft_printf.h"

void	judge_max(t_format *t_node)
{
	if (t_node->prec > t_node->wid)
	{
		if (t_node->prec > t_node->size)
			t_node->max_size = t_node->prec;
		else
			t_node->max_size = t_node->size;
	}
	else
	{
		if (t_node->wid > t_node->size)
			t_node->max_size = t_node->wid;
		else
			t_node->max_size = t_node->size;
	}
}

void	n_judge_max(t_format *t_node)
{
	if (t_node->prec > t_node->wid)
	{
		if (t_node->prec > t_node->size)
			t_node->max_size = t_node->prec + 1;
		else
			t_node->max_size = t_node->size;
	}
	else
	{
		if (t_node->wid > t_node->size)
			t_node->max_size = t_node->wid;
		else
			t_node->max_size = t_node->size;
	}
}
