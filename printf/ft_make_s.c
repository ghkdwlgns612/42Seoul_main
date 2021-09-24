/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:53:25 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:53:33 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_noflag(t_format *inform, char *str)
{
	int i;
	int size;

	i = 0;
	size = inform->size;
	if (inform->flag[2] == 1)
	{
		if (inform->prec < inform->size)
			size = inform->prec;
	}
	if (str != NULL)
	{
		while (size + i < inform->wid)
		{
			inform->result[i++] = ' ';
		}
		while (*str != 0 && size > 0)
		{
			inform->result[i++] = *str++;
			size--;
		}
	}
}

void	s_flag_minus(t_format *inform, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (inform->flag[2] == 1)
	{
		while (j < inform->size && i < inform->prec)
			inform->result[i++] = str[j++];
	}
	else
	{
		while (j < inform->size)
			inform->result[i++] = str[j++];
	}
	while (i < inform->wid)
		inform->result[i++] = ' ';
}

void	s_flag_zero(t_format *inform, char *str)
{
	int i;
	int size;

	i = 0;
	size = inform->size;
	if (inform->flag[2] == 1)
	{
		if (inform->prec < inform->size)
			size = inform->prec;
	}
	if (str != NULL)
	{
		while (size + i < inform->wid)
		{
			inform->result[i++] = '0';
		}
		while (*str != 0 && size > 0)
		{
			inform->result[i++] = *str++;
			size--;
		}
	}
}
