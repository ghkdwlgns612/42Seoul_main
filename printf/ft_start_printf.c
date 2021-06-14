/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:59:40 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/02 02:00:59 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	start_printf(t_format *t_node)
{
	while (*t_node->str != 0)
	{
		if (*t_node->str == '%')
		{
			t_node->str++;
			check_flag(t_node);
			check_wid(t_node);
			check_prec(t_node);
			check_spec(t_node);
			if (t_node->spec == '0')
				return ;
			two_flag(t_node);
			ft_output(t_node);
			ft_putstr(t_node);
			init_node(t_node);
		}
		else
		{
			ft_putchar(*t_node->str);
			t_node->str++;
			t_node->nums++;
		}
	}
}

void	ft_output(t_format *t_node)
{
	if (t_node->spec == 'c')
		ft_output_c(t_node);
	else if (t_node->spec == 's')
		ft_output_s(t_node);
	else if (t_node->spec == 'd')
		ft_output_d(t_node);
	else if (t_node->spec == 'i')
		ft_output_d(t_node);
	else if (t_node->spec == 'c')
		ft_output_c(t_node);
	else if (t_node->spec == 'p')
		ft_output_p(t_node);
	else if (t_node->spec == 'u')
		ft_output_u(t_node);
	else if (t_node->spec == 'x')
		ft_output_x(t_node);
	else if (t_node->spec == 'X')
		ft_output_x(t_node);
	else if (t_node->spec == '%')
		ft_output_percent(t_node);
}

void	two_flag(t_format *t_node)
{
	if (t_node->flag[0] == 1 && t_node->flag[1] == 1)
		t_node->flag[1] = 0;
}
