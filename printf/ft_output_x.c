/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:54:30 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:54:36 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_x(t_format *inform)
{
	int	num;
	int	i;

	num = (unsigned int)va_arg(inform->ap, int);
	if (inform->spec == 'x')
		sx_to_str(inform, num);
	else
		bx_to_str(inform, num);
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
