/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 00:55:22 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/02 00:57:26 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_u(t_format *t_node)
{
	unsigned int	u;
	int				i;

	u = (unsigned int)va_arg(t_node->ap, unsigned int);
	u_to_str(t_node, u);
	exception_null(t_node, u);
	judge_max(t_node);
	i = t_node->max_size;
	if ((t_node->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(t_node->result, t_node->max_size);
	t_node->result[t_node->max_size] = 0;
	if (t_node->flag[0] == 1)
		flag_minus(t_node, t_node->num);
	else if (t_node->flag[1] == 1)
		flag_zero(t_node, t_node->num);
	else
		noflag(t_node, t_node->num);
}
