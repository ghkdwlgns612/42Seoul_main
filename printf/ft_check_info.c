/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:35:12 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/01 10:20:50 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_star(t_format *t_node)
{
	int num;

	num = 0;
	if (*t_node->str == '*')
	{
		t_node->flag[3] = 1;
		num = va_arg(t_node->ap, int);
		t_node->str++;
	}
	return (num);
}

void	check_spec(t_format *t_node)
{
	if (*t_node->str == 'c')
		t_node->spec = 'c';
	else if (*t_node->str == 's')
		t_node->spec = 's';
	else if (*t_node->str == 'd')
		t_node->spec = 'd';
	else if (*t_node->str == 'p')
		t_node->spec = 'p';
	else if (*t_node->str == 'i')
		t_node->spec = 'i';
	else if (*t_node->str == 'u')
		t_node->spec = 'u';
	else if (*t_node->str == 'x')
		t_node->spec = 'x';
	else if (*t_node->str == 'X')
		t_node->spec = 'X';
	else if (*t_node->str == '%')
		t_node->spec = '%';
	else
		t_node->spec = '0';
	t_node->str++;
}

void	check_flag(t_format *t_node)
{
	while (1)
	{
		if (*t_node->str == '-')
			t_node->flag[0] = 1;
		else if (*t_node->str == '0')
			t_node->flag[1] = 1;
		else if (*t_node->str == ' ')
		{
			ft_putchar(*t_node->str);
			t_node->nums++;
		}
		else
			return ;
		t_node->str++;
	}
}

void	check_wid(t_format *t_node)
{
	int answer;

	t_node->wid = check_star(t_node);
	if (t_node->wid > 0)
		return ;
	else if (t_node->wid < 0)
	{
		t_node->wid = t_node->wid * -1;
		t_node->flag[0] = 1;
		return ;
	}
	answer = 0;
	while (*t_node->str == ' ' || (*t_node->str >= 9 && *t_node->str <= 13))
		t_node->str++;
	while (*t_node->str >= '0' && *t_node->str <= '9')
	{
		answer = answer * 10 + (*t_node->str - 48);
		t_node->str++;
	}
	t_node->wid = answer;
}

void	check_prec(t_format *t_node)
{
	int answer;

	answer = 0;
	if (*t_node->str == '.')
	{
		t_node->flag[2] = 1;
		t_node->str++;
		t_node->prec = check_star(t_node);
		if (t_node->prec > 0)
			return ;
		else if (t_node->prec < 0)
		{
			t_node->flag[2] = 0;
			t_node->prec = 0;
			return ;
		}
		while (*t_node->str >= '0' && *t_node->str <= '9')
		{
			answer = answer * 10 + (*t_node->str - 48);
			t_node->str++;
		}
		t_node->prec = answer;
	}
	else
		return ;
}
