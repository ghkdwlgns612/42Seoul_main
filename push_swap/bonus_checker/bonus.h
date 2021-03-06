/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:18:17 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/13 06:45:26 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10200
# endif

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}			t_stack;

t_stack			*init_stack(void);
t_node			*init_node(void);
t_node			*link_stack(t_stack **stack_a, int argc, char **argv);

size_t			ft_strlen(const char *str);
int				ft_strlen_gnl(char *s);
char			*ft_strjoin_gnl(char *save, char *buff);
bool			ft_strcmp(char *s1, char *s2);
int				get_next_line(int fd, char **line);
char			**ft_split(char const *s, char c);

void			ft_error(void);
void			ft_putendl_fd(char *s, int fd);
long long		ft_atoi(const char *str);

int				ft_check(const char *str);
void			ft_check_duplicate(t_node *node);

void			checker(t_stack *a, t_stack *b);
void			push(t_stack *poped, t_stack *pushed);
void			one_stack_reverse_rotate(t_stack *stack);
void			all_stack_reverse_rotate(t_stack *stack_a, t_stack *stack_b);
void			one_stack_rotate(t_stack *stack);
void			all_stack_rotate(t_stack *stack_a, t_stack *stack_b);
void			one_stack_swap(t_stack *stack);
void			all_stack_swap(t_stack *stack_a, t_stack *stack_b);

#endif
