/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:56:12 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/10 11:22:54 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_semi;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	lst_semi = *lst;
	while (lst_semi->next != NULL)
	{
		lst_semi = lst_semi->next;
	}
	lst_semi->next = new;
}
