/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:54:13 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:54:19 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_null(t_format *inform, char **str)
{
	inform->size = 6;
	*str = "(null)";
}

void	ft_output_s(t_format *inform)
{
	char	*str;
	int		i;

	str = va_arg(inform->ap, char *);
	inform->size = pf_strlen(str);
	if (inform->size == 0 && str == NULL)
		check_null(inform, &str);
	judge_max(inform);
	i = inform->max_size;
	if ((inform->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(inform->result, inform->max_size + 1);
	if (inform->flag[0] == 1)
		s_flag_minus(inform, str);
	else if (inform->flag[1] == 1)
		s_flag_zero(inform, str);
	else
		s_noflag(inform, str);
}
