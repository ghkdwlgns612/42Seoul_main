/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:50:55 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:51:02 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	judge_max(t_format *inform)
{
	if (inform->prec > inform->wid)
	{
		if (inform->prec > inform->size)
			inform->max_size = inform->prec;
		else
			inform->max_size = inform->size;
	}
	else
	{
		if (inform->wid > inform->size)
			inform->max_size = inform->wid;
		else
			inform->max_size = inform->size;
	}
}

void	n_judge_max(t_format *inform)
{
	if (inform->prec > inform->wid)
	{
		if (inform->prec > inform->size)
			inform->max_size = inform->prec + 1;
		else
			inform->max_size = inform->size;
	}
	else
	{
		if (inform->wid > inform->size)
			inform->max_size = inform->wid;
		else
			inform->max_size = inform->size;
	}
}
