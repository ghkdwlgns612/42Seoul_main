/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 00:26:19 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/02 00:33:47 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_d(t_format *t_node)
{
	int num;

	num = va_arg(t_node->ap, int);
	if (num >= 0)
		positive_d(t_node, num);
	else
		negative_d(t_node, num);
}

void	positive_d(t_format *t_node, int num)
{
	int	i;

	d_to_str(t_node, num);
	exception_null(t_node, num);
	judge_max(t_node);
	i = t_node->max_size;
	if ((t_node->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(t_node->result, t_node->max_size + 1);
	if (t_node->flag[0] == 1)
		flag_minus(t_node, t_node->num);
	else if (t_node->flag[1] == 1)
		flag_zero(t_node, t_node->num);
	else
		noflag(t_node, t_node->num);
}

void	negative_d(t_format *t_node, int num)
{
	int	i;

	d_to_str(t_node, num);
	n_judge_max(t_node);
	i = t_node->max_size;
	if ((t_node->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(t_node->result, t_node->max_size + 1);
	if (t_node->flag[0] == 1)
		n_flag_minus(t_node, t_node->num);
	else if (t_node->flag[1] == 1)
		n_flag_zero(t_node, t_node->num);
	else
		n_noflag(t_node, t_node->num);
}

void	exception_null(t_format *t_node, int num)
{
	if (t_node->flag[2] == 1 && t_node->prec == 0 && num == 0)
	{
		t_node->num[0] = 0;
		t_node->num[1] = 0;
		t_node->size = 0;
	}
}
