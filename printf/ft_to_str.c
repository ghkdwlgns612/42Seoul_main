/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 02:01:28 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/02 03:25:21 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		g_hex_s[17] = "0123456789abcdef";
char		g_hex_b[17] = "0123456789ABCDEF";

void	d_to_str(t_format *t_node, int n)
{
	int				len;
	unsigned int	tmp;

	if (n == 0)
	{
		t_node->num[0] = '0';
		t_node->num[1] = 0;
		t_node->size = 1;
		return ;
	}
	len = check_size(n);
	if (n < 0)
	{
		tmp = n * -1;
		len++;
		t_node->num[0] = '-';
	}
	else
		tmp = n;
	t_node->size = len;
	t_node->num[len] = 0;
	len--;
	do_itoa(tmp, t_node, len);
}

void	u_to_str(t_format *t_node, unsigned int n)
{
	int				len;
	unsigned int	tmp;

	if (n == 0)
	{
		t_node->num[0] = '0';
		t_node->num[1] = 0;
		t_node->size = 1;
		return ;
	}
	len = check_size(n);
	tmp = n;
	t_node->size = len;
	t_node->num[len] = 0;
	len--;
	do_itoa(tmp, t_node, len);
}

void	h_to_str(long long addr, t_format *t_node)
{
	long long	temp;
	int			len;

	len = 0;
	temp = addr;
	while (addr != 0)
	{
		addr /= 16;
		len++;
	}
	len = len == 0 ? 3 : len + 2;
	t_node->size = len;
	addr = temp;
	while (addr != 0)
	{
		t_node->num[--len] = g_hex_s[addr % 16];
		addr /= 16;
	}
	t_node->num[0] = '0';
	t_node->num[1] = 'x';
	t_node->num[2] = temp == 0 ? '0' : t_node->num[2];
}

void	sx_to_str(t_format *t_node, unsigned int addr)
{
	long long	temp;
	int			len;

	if (addr == 0)
	{
		t_node->num[0] = '0';
		t_node->size = 1;
		return ;
	}
	len = 0;
	temp = addr;
	while (addr != 0)
	{
		addr /= 16;
		len++;
	}
	len = len == 0 ? 0 : len;
	t_node->size = len;
	addr = temp;
	while (addr != 0)
	{
		t_node->num[--len] = g_hex_s[addr % 16];
		addr /= 16;
	}
}

void	bx_to_str(t_format *t_node, unsigned int addr)
{
	long long	temp;
	int			len;

	if (addr == 0)
	{
		t_node->num[0] = '0';
		t_node->size = 1;
		return ;
	}
	len = 0;
	temp = addr;
	while (addr != 0)
	{
		addr /= 16;
		len++;
	}
	len = len == 0 ? 0 : len;
	t_node->size = len;
	addr = temp;
	while (addr != 0)
	{
		t_node->num[--len] = g_hex_b[addr % 16];
		addr /= 16;
	}
}
