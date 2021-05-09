/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:39:51 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/09 15:11:59 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
	{
		if (end == 1)
			break ;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	if ((str = (char *)malloc((end - start + 1))) == 0)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
