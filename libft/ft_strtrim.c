/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:39:51 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/10 16:11:38 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*res;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	len = ft_strlen(s1);
	while (len && s1[len - 1] && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(res, s1, len);
	res[len] = '\0';
	return (res);
}
