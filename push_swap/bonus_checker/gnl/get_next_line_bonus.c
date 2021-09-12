/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:34:04 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 21:43:57 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../bonus.h"

int	ft_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_split_line(char **line, char **static_str, int flag)
{
	char	*temp;
	int		len;

	(*static_str)[flag] = 0;
	len = ft_strlen(*static_str + flag + 1);
	*line = ft_strdup(*static_str);
	if (len == 0)
	{
		free(*static_str);
		*static_str = 0;
		return (1);
	}
	temp = ft_strdup(*static_str + flag + 1);
	free(*static_str);
	*static_str = temp;
	return (1);
}

int	ft_return(char **static_str, char **line)
{
	int	flag;

	flag = ft_newline(*static_str);
	if (*static_str && flag >= 0)
		return (ft_split_line(line, static_str, flag));
	else if (*static_str)
	{
		*line = *static_str;
		*static_str = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	ssize_t			read_index;
	static char		*str[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				flag;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	read_index = read(fd, buf, BUFFER_SIZE);
	while (read_index > 0)
	{
		if (str[fd] == 0)
			str[fd] = ft_strdup("");
		buf[read_index] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
		flag = ft_newline(str[fd]);
		if (flag >= 0)
			return (ft_split_line(line, &str[fd], flag));
		read_index = read(fd, buf, BUFFER_SIZE);
	}
	if (read_index < 0)
		return (-1);
	return (ft_return(&str[fd], line));
}
