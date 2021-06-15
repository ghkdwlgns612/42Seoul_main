/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:52:22 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 14:01:52 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	start_printf(t_format *inform)
{
	while (*inform->str != 0)
	{
		if (*inform->str == '%')
		{
			inform->str++;
			check_flag(inform);
			check_wid(inform);
			check_prec(inform);
			check_spec(inform);
			if (inform->spec == '0')
				return ;
			two_flag(inform);
			ft_output(inform);
			ft_putstr(inform);
			init_node(inform);
		}
		else
		{
			ft_putchar(*inform->str);
			inform->str++;
			inform->nums++;
		}
	}
}

void	ft_output(t_format *inform)
{
	if (inform->spec == 'c')
		ft_output_c(inform);
	else if (inform->spec == 's')
		ft_output_s(inform);
	else if (inform->spec == 'd')
		ft_output_d(inform);
	else if (inform->spec == 'i')
		ft_output_d(inform);
	else if (inform->spec == 'c')
		ft_output_c(inform);
	else if (inform->spec == 'p')
		ft_output_p(inform);
	else if (inform->spec == 'u')
		ft_output_u(inform);
	else if (inform->spec == 'x')
		ft_output_x(inform);
	else if (inform->spec == 'X')
		ft_output_x(inform);
	else if (inform->spec == '%')
		ft_output_percent(inform);
}

void	two_flag(t_format *inform)
{
	if (inform->flag[0] == 1 && inform->flag[1] == 1)
		inform->flag[1] = 0;
}
