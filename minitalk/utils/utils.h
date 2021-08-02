#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <signal.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4095

# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10200

# endif

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_newline(char *str);
int		ft_split_line(char **line, char **static_str, int flag);
int		ft_return(char **static_str, char **line);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_atoi(const char *str);
#endif