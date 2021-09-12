/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:11:14 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 20:13:06 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push.h"

void	three_top_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		one_stack_rotate(b, 'B');
		if (b->top->next->value == max)
			one_stack_swap(b, 'B');
	}
	else
	{
		one_stack_swap(b, 'B');
		one_stack_rotate(b, 'B');
		one_stack_swap(b, 'B');
		one_stack_reverse_rotate(b, 'B');
		if (b->top->next->value == max)
			one_stack_swap(b, 'B');
	}
}

void	three_middle_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		one_stack_reverse_rotate(b, 'B');
		if (b->top->next->value == max)
			one_stack_swap(b, 'B');
	}
	else
	{
		one_stack_rotate(b, 'B');
		one_stack_swap(b, 'B');
		one_stack_reverse_rotate(b, 'B');
		if (b->top->next->value == max)
			one_stack_swap(b, 'B');
	}
}

void	three_bottom_min_b(t_stack *b, int max)
{
	if (b->top->next->value == max)
		one_stack_swap(b, 'B');
}

void	three_b(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = get_min_value(3, b->top);
	max = get_max_value(3, b->top);
	if (b->top->value == min)
		three_top_min_b(b, max);
	else if (b->top->next->value == min)
		three_middle_min_b(b, max);
	else if (b->top->next->next->value == min)
		three_bottom_min_b(b, max);
	push(b, a, 'A');
	push(b, a, 'A');
	push(b, a, 'A');
}
