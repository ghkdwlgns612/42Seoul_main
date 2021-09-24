/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:51:12 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:51:21 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_d(t_format *inform)
{
	int num;

	num = va_arg(inform->ap, int);
	if (num >= 0)
		positive_d(inform, num);
	else
		negative_d(inform, num);
}

void	positive_d(t_format *inform, int num)
{
	int	i;

	d_to_str(inform, num);
	exception_null(inform, num);
	judge_max(inform);
	i = inform->max_size;
	if ((inform->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(inform->result, inform->max_size + 1);
	if (inform->flag[0] == 1)
		flag_minus(inform, inform->num);
	else if (inform->flag[1] == 1)
		flag_zero(inform, inform->num);
	else
		noflag(inform, inform->num);
}

void	negative_d(t_format *inform, int num)
{
	int	i;

	d_to_str(inform, num);
	n_judge_max(inform);
	i = inform->max_size;
	if ((inform->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(inform->result, inform->max_size + 1);
	if (inform->flag[0] == 1)
		n_flag_minus(inform, inform->num);
	else if (inform->flag[1] == 1)
		n_flag_zero(inform, inform->num);
	else
		n_noflag(inform, inform->num);
}

void	exception_null(t_format *inform, int num)
{
	if (inform->flag[2] == 1 && inform->prec == 0 && num == 0)
	{
		inform->num[0] = 0;
		inform->num[1] = 0;
		inform->size = 0;
	}
}
