/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:03:24 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 20:16:56 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push.h"

void	arg_five(t_stack *a, t_stack *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = get_mid_value(a->top);
	while (1)
	{
		if (a->top->value < mid)
		{
			push(a, b, 'B');
			pb++;
		}
		else
			one_stack_rotate(a, 'A');
		if (pb == 2)
			break ;
	}
	three_a(a);
	two(a, b, 'B');
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	res_cnt;

	res_cnt = 0;
	if (a->size == 5)
		arg_five(a, b);
	else
		a_to_b(a->size, a, b, &res_cnt);
}
