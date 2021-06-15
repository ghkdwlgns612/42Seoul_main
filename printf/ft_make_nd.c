/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_nd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:50:35 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:50:42 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	n_noflag(t_format *inform, char *str)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	if (str != NULL)
	{
		str++;
		size = inform->size;
		if (inform->size <= inform->prec)
			size = inform->prec + 1;
		while (size + i < inform->wid)
			inform->result[i++] = ' ';
		inform->result[i++] = '-';
		while (inform->size + j - 1 < inform->prec)
		{
			inform->result[i++] = '0';
			j++;
		}
		while (*str != 0)
			inform->result[i++] = *str++;
	}
}

void	n_flag_minus(t_format *inform, char *str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		str++;
		inform->result[i++] = '-';
		while (inform->size + i - 2 < inform->prec)
			inform->result[i++] = '0';
		while (*str != 0)
			inform->result[i++] = *str++;
		while (i < inform->max_size)
			inform->result[i++] = ' ';
	}
}

void	n_flag_zero(t_format *inform, char *str)
{
	int i;
	int j;

	i = 0;
	str++;
	j = inform->max_size - inform->size;
	if (inform->flag[2] == 1)
	{
		if (inform->prec >= inform->size)
			j = inform->max_size - inform->prec - 1;
		while (j-- > 0)
			inform->result[i++] = ' ';
		inform->result[i++] = '-';
		j = inform->prec - inform->size + 1;
		while (j-- > 0)
			inform->result[i++] = '0';
		while (*str != 0)
			inform->result[i++] = *str++;
	}
	else
	{
		n_flag_zero_2(inform, str);
	}
}

void	n_flag_zero_2(t_format *inform, char *str)
{
	int i;
	int j;

	i = 0;
	j = inform->max_size - inform->size;
	inform->result[i++] = '-';
	while (j-- > 0)
		inform->result[i++] = '0';
	while (*str != 0)
		inform->result[i++] = *str++;
}
