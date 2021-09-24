/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:44:23 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/10 12:20:26 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_eli;
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	if (!(new_eli = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_lst = new_eli;
	lst = lst->next;
	while (lst)
	{
		if (!(new_eli = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_eli);
	}
	return (new_eli);
}
