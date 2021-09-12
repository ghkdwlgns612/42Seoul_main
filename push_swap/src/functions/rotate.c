/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:23:10 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 21:27:12 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push.h"

void	one_stack_rotate(t_stack *stack, char name)
{
	t_node	*temp;
	t_node	*next;
	t_node	*last;

	if ((stack)->size < 2)
		return ;
	temp = (stack)->top;
	next = (stack)->top->next;
	last = (stack)->bottom;
	(stack)->top = next;
	next->prev = NULL;
	if ((stack)->size == 2)
	{
		temp->prev = next;
		temp->next = NULL;
		next->next = temp;
	}
	else
	{
		temp->next = NULL;
		last->next = temp;
		temp->prev = last;
	}
	(stack)->bottom = temp;
	ft_print_rotate(name);
}

void	all_stack_rotate(t_stack *stack_a, t_stack *stack_b, char name)
{
	one_stack_rotate(stack_a, name);
	one_stack_rotate(stack_b, name);
	if (name == 'C')
		ft_putendl_fd("rr", 1);
}

void	ft_print_rotate(char name)
{
	if (name == 'A')
		ft_putendl_fd("ra", 1);
	else if (name == 'B')
		ft_putendl_fd("rb", 1);
}
