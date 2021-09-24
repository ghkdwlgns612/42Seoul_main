/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_two_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:04:21 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 21:09:55 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push.h"

void	two(t_stack *a, t_stack *b, char name)
{
	if (name == 'A')
	{
		if (a->top->value > a->top->next->value)
			one_stack_swap(a, 'A');
	}
	else
	{
		if (b->top->value < b->top->next->value)
			one_stack_swap(b, 'B');
		push(b, a, 'A');
		push(b, a, 'A');
	}
}

void	one_two_three(int r_num, t_stack *a, t_stack *b, char name)
{
	if (r_num == 3)
	{
		if (name == 'A')
			three_a(a);
		else
			three_b(a, b);
	}
	else if (r_num == 2)
		two(a, b, name);
	else if (r_num == 1)
	{
		if (name == 'B')
			push(b, a, 'A');
	}
}
