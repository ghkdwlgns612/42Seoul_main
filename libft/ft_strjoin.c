/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:02:06 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/09 13:22:42 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		s1_index;
	int		s2_index;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == 0)
		return (0);
	s1_index = 0;
	while (s1_index < s1_len)
	{
		str[s1_index] = s1[s1_index];
		s1_index++;
	}
	s2_index = 0;
	while (s2_index < s2_len)
		str[s1_index++] = s2[s2_index++];
	str[s1_index] = '\0';
	return (str);
}
