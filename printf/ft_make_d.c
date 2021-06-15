/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:53:12 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:53:19 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero(t_format *inform, char *str)
{
	int i;
	int j;

	i = 0;
	j = inform->max_size - inform->size;
	if (inform->flag[2] == 1)
	{
		if (inform->prec > inform->size)
			j = inform->max_size - inform->prec;
		while (j-- > 0)
			inform->result[i++] = ' ';
		j = inform->prec - inform->size;
		while (j-- > 0)
			inform->result[i++] = '0';
		while (*str != 0)
			inform->result[i++] = *str++;
	}
	else
	{
		while (j-- > 0)
			inform->result[i++] = '0';
		while (*str != 0)
			inform->result[i++] = *str++;
	}
}

void	flag_minus(t_format *inform, char *str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (inform->prec > inform->size + i)
			inform->result[i++] = '0';
		while (*str != 0)
			inform->result[i++] = *str++;
		while (i < inform->max_size)
			inform->result[i++] = ' ';
	}
}

void	noflag(t_format *inform, char *str)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	if (str != NULL)
	{
		size = inform->size;
		if (inform->size < inform->prec)
			size = inform->prec;
		while (inform->wid > size + i)
			inform->result[i++] = ' ';
		while (inform->size + j < inform->prec)
		{
			inform->result[i++] = '0';
			j++;
		}
		while (*str != 0)
			inform->result[i++] = *str++;
	}
}
