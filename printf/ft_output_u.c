/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:51:47 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:51:54 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_u(t_format *inform)
{
	unsigned int	u;
	int				i;

	u = (unsigned int)va_arg(inform->ap, unsigned int);
	u_to_str(inform, u);
	exception_null(inform, u);
	judge_max(inform);
	i = inform->max_size;
	if ((inform->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(inform->result, inform->max_size);
	inform->result[inform->max_size] = 0;
	if (inform->flag[0] == 1)
		flag_minus(inform, inform->num);
	else if (inform->flag[1] == 1)
		flag_zero(inform, inform->num);
	else
		noflag(inform, inform->num);
}
