/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:49:44 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:49:56 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_star(t_format *inform)
{
	int num;

	num = 0;
	if (*inform->str == '*')
	{
		inform->flag[3] = 1;
		num = va_arg(inform->ap, int);
		inform->str++;
	}
	return (num);
}

void	check_spec(t_format *inform)
{
	if (*inform->str == 'c')
		inform->spec = 'c';
	else if (*inform->str == 's')
		inform->spec = 's';
	else if (*inform->str == 'd')
		inform->spec = 'd';
	else if (*inform->str == 'p')
		inform->spec = 'p';
	else if (*inform->str == 'i')
		inform->spec = 'i';
	else if (*inform->str == 'u')
		inform->spec = 'u';
	else if (*inform->str == 'x')
		inform->spec = 'x';
	else if (*inform->str == 'X')
		inform->spec = 'X';
	else if (*inform->str == '%')
		inform->spec = '%';
	else
		inform->spec = '0';
	inform->str++;
}

void	check_flag(t_format *inform)
{
	while (1)
	{
		if (*inform->str == '-')
			inform->flag[0] = 1;
		else if (*inform->str == '0')
			inform->flag[1] = 1;
		else if (*inform->str == ' ')
		{
			ft_putchar(*inform->str);
			inform->nums++;
		}
		else
			return ;
		inform->str++;
	}
}

void	check_wid(t_format *inform)
{
	int answer;

	inform->wid = check_star(inform);
	if (inform->wid > 0)
		return ;
	else if (inform->wid < 0)
	{
		inform->wid = inform->wid * -1;
		inform->flag[0] = 1;
		return ;
	}
	answer = 0;
	while (*inform->str == ' ' || (*inform->str >= 9 && *inform->str <= 13))
		inform->str++;
	while (*inform->str >= '0' && *inform->str <= '9')
	{
		answer = answer * 10 + (*inform->str - 48);
		inform->str++;
	}
	inform->wid = answer;
}

void	check_prec(t_format *inform)
{
	int answer;

	answer = 0;
	if (*inform->str == '.')
	{
		inform->flag[2] = 1;
		inform->str++;
		inform->prec = check_star(inform);
		if (inform->prec > 0)
			return ;
		else if (inform->prec < 0)
		{
			inform->flag[2] = 0;
			inform->prec = 0;
			return ;
		}
		while (*inform->str >= '0' && *inform->str <= '9')
		{
			answer = answer * 10 + (*inform->str - 48);
			inform->str++;
		}
		inform->prec = answer;
	}
	else
		return ;
}
