/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:09:53 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 22:12:10 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../bonus.h"

void	one_size_push(t_stack *poped, t_stack *pushed)
{
	if (pushed->size == 0)
	{
		pushed->top = poped->top;
		pushed->bottom = pushed->top;
	}
	else
	{
		pushed->top->prev = poped->top;
		poped->top->next = pushed->top;
		pushed->top = pushed->top->prev;
	}
	poped->top = NULL;
	poped->bottom = NULL;
}

void	general_push(t_stack *poped, t_stack *pushed)
{
	if (pushed->size == 0)
	{
		pushed->top = poped->top;
		pushed->bottom = pushed->top;
		poped->top = poped->top->next;
		pushed->top->next = NULL;
		poped->top->prev = NULL;
	}
	else
	{
		pushed->top->prev = poped->top;
		poped->top = poped->top->next;
		poped->top->prev = NULL;
		pushed->top->prev->next = pushed->top;
		pushed->top = pushed->top->prev;
	}
}

void	push(t_stack *poped, t_stack *pushed)
{
	if (poped->size == 0)
		return ;
	if (poped->size == 1)
		one_size_push(poped, pushed);
	else
		general_push(poped, pushed);
	pushed->size++;
	poped->size--;
}
