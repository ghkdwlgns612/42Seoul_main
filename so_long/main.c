#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void		ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == 0 || fd < 0)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

void	ft_exit(char *str)
{
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
}

t_size ft_size_map(int fd)
{
	t_size tmp;
	char *line;
	int	row;
	int	col;
	int res;

	line = NULL;
	row = 0;
	res = 1;
	while (res)
	{
		res = get_next_line(fd,&line);
		row++;
		col = ft_strlen_gnl(line);
		free(line);
		if (!res)
			break ;
	}
	tmp.row_size = row;
	tmp.col_size = col;
	return tmp;
}

char	**ft_fill_map(char **matrix, t_size size,  char *argv)
{
	int ret;
	int i;
	int j;
	int fd;
	char *line;

	i = 0;
	j = 0;
	ret = 1;
	line = NULL;
	fd = open(argv,O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		j = -1;
		if ((int)ft_strlen(line) - 1 != size.col_size && ret != 0)
			ft_exit("No rectangul");
		while (++j < size.col_size)
			matrix[i][j] = line[j];
		i++;
		free(line);
		if (!ret)
			break ;
	}
	close(fd);
	return matrix;
}

char	**ft_create_map(t_size size, char *argv)
{
	char **matrix;
	int k;

	k = 0;
	matrix = (char **)malloc(size.row_size * sizeof(char *));
	while (k < size.row_size)
	{
		matrix[k] = (char *)malloc(size.col_size * sizeof(char));
		k++;
	}	
	matrix = ft_fill_map(matrix, size, argv);
	return matrix;
}

t_unit make_unit(int fd, char *argv)
{
	t_unit tmp;
	t_size size;

	size = ft_size_map(fd);
	tmp.map.height = size.row_size;
	tmp.map.width = size.col_size;
	tmp.map.matrix = ft_create_map(size, argv);
}

//-Wall -Wextra -Werror -g3 -fsanitize=address
int		main(int argc, char **argv)
{
	int fd;
	t_unit unit;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		unit = make_unit(fd, argv[1]);
		close(fd);
	}
	else
	{
		exit(1);
	}
}


