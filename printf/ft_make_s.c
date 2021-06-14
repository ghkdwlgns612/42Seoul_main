/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 00:17:10 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/03 16:14:24 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_noflag(t_format *t_node, char *str)
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
	if (str != NULL)
	{
		while (size + i < t_node->wid)
		{
			t_node->result[i++] = ' ';
		}
		while (*str != 0 && size > 0)
		{
			t_node->result[i++] = *str++;
			size--;
		}
	}
}

void	s_flag_minus(t_format *t_node, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (t_node->flag[2] == 1)
	{
		while (j < t_node->size && i < t_node->prec)
			t_node->result[i++] = str[j++];
	}
	else
	{
		while (j < t_node->size)
			t_node->result[i++] = str[j++];
	}
	while (i < t_node->wid)
		t_node->result[i++] = ' ';
}

void	s_flag_zero(t_format *t_node, char *str)
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
	if (str != NULL)
	{
		while (size + i < t_node->wid)
		{
			t_node->result[i++] = '0';
		}
		while (*str != 0 && size > 0)
		{
			t_node->result[i++] = *str++;
			size--;
		}
	}
}
