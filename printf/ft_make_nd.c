/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_nd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 00:13:04 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/02 00:13:07 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	n_noflag(t_format *t_node, char *str)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	if (str != NULL)
	{
		str++;
		size = t_node->size;
		if (t_node->size <= t_node->prec)
			size = t_node->prec + 1;
		while (t_node->wid > size + i)
			t_node->result[i++] = ' ';
		t_node->result[i++] = '-';
		while (t_node->size + j - 1 < t_node->prec)
		{
			t_node->result[i++] = '0';
			j++;
		}
		while (*str != 0)
			t_node->result[i++] = *str++;
	}
}

void	n_flag_minus(t_format *t_node, char *str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		str++;
		t_node->result[i++] = '-';
		while (t_node->prec > t_node->size + i - 2)
			t_node->result[i++] = '0';
		while (*str != 0)
			t_node->result[i++] = *str++;
		while (i < t_node->max_size)
			t_node->result[i++] = ' ';
	}
}

void	n_flag_zero(t_format *t_node, char *str)
{
	int i;
	int j;

	i = 0;
	str++;
	j = t_node->max_size - t_node->size;
	if (t_node->flag[2] == 1)
	{
		if (t_node->prec >= t_node->size)
			j = t_node->max_size - t_node->prec - 1;
		while (j-- > 0)
			t_node->result[i++] = ' ';
		t_node->result[i++] = '-';
		j = t_node->prec - t_node->size + 1;
		while (j-- > 0)
			t_node->result[i++] = '0';
		while (*str != 0)
			t_node->result[i++] = *str++;
	}
	else
	{
		n_flag_zero_2(t_node, str);
	}
}

void	n_flag_zero_2(t_format *t_node, char *str)
{
	int i;
	int j;

	i = 0;
	j = t_node->max_size - t_node->size;
	t_node->result[i++] = '-';
	while (j-- > 0)
		t_node->result[i++] = '0';
	while (*str != 0)
		t_node->result[i++] = *str++;
}
