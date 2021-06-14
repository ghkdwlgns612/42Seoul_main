/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 00:33:58 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/02 00:37:39 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_flag_minus(t_format *t_node, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str != NULL)
	{
		str++;
		str++;
		t_node->result[i++] = '0';
		t_node->result[i++] = 'x';
		while (t_node->prec > t_node->size + i - 3)
			t_node->result[i++] = '0';
		while (*str != 0)
			t_node->result[i++] = *str++;
		while (i < t_node->max_size)
			t_node->result[i++] = ' ';
	}
}

void	p_noflag(t_format *t_node, char *str)
{
	int i;
	int j;

	i = 0;
	str++;
	str++;
	j = t_node->max_size - t_node->size;
	if (t_node->prec > t_node->size)
		j = t_node->max_size - t_node->prec - 2;
	while (j-- > 0)
		t_node->result[i++] = ' ';
	t_node->result[i++] = '0';
	t_node->result[i++] = 'x';
	j = t_node->prec - t_node->size + 2;
	while (j-- > 0)
		t_node->result[i++] = '0';
	while (*str != 0)
		t_node->result[i++] = *str++;
}

void	ft_output_p(t_format *t_node)
{
	unsigned long int	p;
	int					i;

	p = (unsigned long int)va_arg(t_node->ap, void *);
	h_to_str(p, t_node);
	p_exception_null(t_node, p);
	judge_max(t_node);
	i = t_node->max_size;
	if ((t_node->result = (char *)malloc(sizeof(char) * (i + 3))) == 0)
		return ;
	pf_bzero(t_node->result, t_node->max_size + 3);
	if (t_node->flag[0] == 1)
		p_flag_minus(t_node, t_node->num);
	else
		p_noflag(t_node, t_node->num);
}

void	p_exception_null(t_format *t_node, int num)
{
	if (t_node->flag[2] == 1 && t_node->prec == 0 && num == 0)
	{
		t_node->num[2] = 0;
		t_node->num[3] = 0;
		t_node->size = 2;
	}
}
