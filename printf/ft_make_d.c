/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:14:33 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/01 23:53:19 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero(t_format *t_node, char *str)
{
	int i;
	int j;

	i = 0;
	j = t_node->max_size - t_node->size;
	if (t_node->flag[2] == 1)
	{
		if (t_node->prec > t_node->size)
			j = t_node->max_size - t_node->prec;
		while (j-- > 0)
			t_node->result[i++] = ' ';
		j = t_node->prec - t_node->size;
		while (j-- > 0)
			t_node->result[i++] = '0';
		while (*str != 0)
			t_node->result[i++] = *str++;
	}
	else
	{
		while (j-- > 0)
			t_node->result[i++] = '0';
		while (*str != 0)
			t_node->result[i++] = *str++;
	}
}

void	flag_minus(t_format *t_node, char *str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (t_node->prec > t_node->size + i)
			t_node->result[i++] = '0';
		while (*str != 0)
			t_node->result[i++] = *str++;
		while (i < t_node->max_size)
			t_node->result[i++] = ' ';
	}
}

void	noflag(t_format *t_node, char *str)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	if (str != NULL)
	{
		size = t_node->size;
		if (t_node->size < t_node->prec)
			size = t_node->prec;
		while (t_node->wid > size + i)
			t_node->result[i++] = ' ';
		while (t_node->size + j < t_node->prec)
		{
			t_node->result[i++] = '0';
			j++;
		}
		while (*str != 0)
			t_node->result[i++] = *str++;
	}
}
