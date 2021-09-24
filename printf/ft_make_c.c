/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:50:10 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:50:17 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_noflag(t_format *inform, char c)
{
	int i;
	int size;

	i = 0;
	size = inform->size;
	while (size + i < inform->wid)
	{
		inform->result[i++] = ' ';
	}
	inform->result[i++] = c;
}

void	c_flag_minus(t_format *inform, char c)
{
	int i;

	i = 0;
	inform->result[i++] = c;
	while (i < inform->wid)
		inform->result[i++] = ' ';
}

void	c_flag_zero(t_format *inform, char c)
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
	while (size + i < inform->wid)
	{
		inform->result[i++] = '0';
	}
	inform->result[i++] = c;
}
