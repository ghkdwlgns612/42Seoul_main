/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:15:28 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 22:17:59 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../bonus.h"

void	one_stack_swap(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	if ((stack)->size < 2)
		return ;
	temp = (stack)->top;
	next = (stack)->top->next;
	(stack)->top = next;
	next->prev = NULL;
	temp->prev = next;
	if ((stack)->size == 2)
	{
		temp->next = NULL;
		next->next = temp;
		(stack)->bottom = temp;
	}
	else
	{
		temp->next = next->next;
		next->next->prev = temp;
		next->next = temp;
	}
}

void	all_stack_swap(t_stack *stack_a, t_stack *stack_b)
{	
	one_stack_swap(stack_a);
	one_stack_swap(stack_b);
}
