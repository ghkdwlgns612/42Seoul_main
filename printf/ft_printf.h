/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:18:28 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/02 03:45:02 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_format
{
	char		*str;
	char		flag[4];
	char		spec;
	char		num[21];
	char		*result;
	va_list		ap;
	int			wid;
	int			prec;
	int			size;
	int			max_size;
	int			nums;
}				t_format;

extern	char	g_hex_b[17];
extern	char	g_hex_s[17];

void			exception_null(t_format *t_node, int num);
void			p_exception_null(t_format *t_node, int num);
void			negative_d(t_format *t_node, int num);
void			positive_d(t_format *t_node, int num);
void			n_judge_max(t_format *t_node);
void			init_zero(t_format *t_node);
void			d_check_null(t_format *t_node);
void			check_null(t_format *t_node, char **str);
void			pf_bzero(void *ptr, size_t size);
void			p_flag_minus(t_format *t_node, char *str);
void			p_noflag(t_format *t_node, char *str);
void			percent_flag_zero(t_format *t_node, char c);
void			s_noflag(t_format *t_node, char *str);
void			s_flag_zero(t_format *t_node, char *str);
void			s_flag_minus(t_format *t_node, char *str);
void			c_noflag(t_format *t_node, char c);
void			c_flag_zero(t_format *t_node, char c);
void			c_flag_minus(t_format *t_node, char c);
void			n_flag_zero(t_format *t_node, char *str);
void			n_flag_zero_2(t_format *t_node, char *str);
void			n_flag_minus(t_format *t_node, char *str);
void			n_noflag(t_format *t_node, char *str);
void			flag_zero(t_format *t_node, char *str);
void			flag_minus(t_format *t_node, char *str);
void			noflag(t_format *t_node, char *str);
int				pf_strlen(char *str);
void			judge_max(t_format *t_node);
void			ft_output_x(t_format *t_node);
void			ft_output_u(t_format *t_node);
void			ft_output_p(t_format *t_node);
void			ft_output_s(t_format *t_node);
void			ft_output_d(t_format *t_node);
void			ft_output_c(t_format *t_node);
void			ft_output_percent(t_format *t_node);
void			select_spec(t_format *t_node);
long long		check_size(long long n);
void			do_itoa(unsigned int tmp, t_format *t_node, int len);
void			d_to_str(t_format *t_node, int n);
void			h_to_str(long long addr, t_format *t_node);
void			u_to_str(t_format *t_node, unsigned int n);
void			sx_to_str(t_format *t_node, unsigned int addr);
void			bx_to_str(t_format *t_node, unsigned int addr);
void			check_spec(t_format *t_node);
void			ft_output(t_format *t_node);
int				check_star(t_format *t_node);
void			check_wid(t_format *t_node);
void			check_prec(t_format *t_node);
void			check_percent(t_format *t_node);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putstr(t_format *t_node);
void			init_firstnode(t_format *t_node, char *format);
void			init_node(t_format *t_node);
void			check_flag(t_format *t_node);
void			start_printf(t_format *t_node);
void			two_flag(t_format *t_node);
int				ft_printf(const char *format, ...);

#endif
