/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:51:30 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:51:39 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_percent(t_format *inform)
{
	int		i;
	char	a;

	a = '%';
	inform->size = 1;
	judge_max(inform);
	i = inform->max_size;
	if ((inform->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(inform->result, inform->max_size + 1);
	if (inform->flag[0] == 1)
	{
		c_flag_minus(inform, a);
	}
	else if (inform->flag[1] == 1)
	{
		percent_flag_zero(inform, a);
	}
	else
	{
		c_noflag(inform, a);
	}
}

void	percent_flag_zero(t_format *inform, char c)
{
	int i;
	int size;

	i = 0;
	size = inform->size;
	if (inform->flag[2] == 1)
	{
		if (inform->prec < inform->size)
			size = inform->prec + 1;
	}
	while (size + i < inform->wid)
	{
		inform->result[i++] = '0';
	}
	inform->result[i++] = c;
}
