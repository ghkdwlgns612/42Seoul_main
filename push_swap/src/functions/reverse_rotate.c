/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:20:28 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 21:22:58 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push.h"

void	one_stack_reverse_rotate(t_stack *stack, char name)
{
	t_node	*temp;
	t_node	*last_prev;
	t_node	*last;

	if ((stack)->size < 2)
		return ;
	temp = (stack)->top;
	last_prev = (stack)->bottom->prev;
	last = (stack)->bottom;
	(stack)->top = last;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
	if ((stack)->size == 2)
		temp->next = NULL;
	else
		last_prev->next = NULL;
	(stack)->bottom = last_prev;
	ft_print_reverse_rotate(name);
}

void	all_stack_reverse_rotate(t_stack *a, t_stack *b, char name)
{
	one_stack_reverse_rotate(a, name);
	one_stack_reverse_rotate(b, name);
	if (name == 'C')
		ft_putendl_fd("rrr", 1);
}

void	ft_print_reverse_rotate(char name)
{
	if (name == 'A')
		ft_putendl_fd("rra", 1);
	else if (name == 'B')
		ft_putendl_fd("rrb", 1);
}
