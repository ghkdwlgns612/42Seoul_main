/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:18:28 by ji-park           #+#    #+#             */
/*   Updated: 2021/06/15 15:20:53 by jihuhwan         ###   ########.fr       */
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
	char		*str; // 들어온 format을 저장하는 곳.
	char		flag[4]; // flag[0] = -플래그, flag[1] = 0플래그,flag[2] = .플래그,flag[3] = *플래그
	char		spec; // 어떤 타입으로 출력할지 결정.
	char		num[21]; //출력할 것들을 임시로 저장하는 buffer.
	char		*result; //출력할 결과를 저장.
	va_list		ap;
	int			wid; // 폭을 구함. atoi와 비슷
	int			prec; //.뒤에 붙은 숫자(precision)
	int			size; //문자의 길이.
	int			max_size; //전체 출력 공간.(|    |)
	int			nums; //출력할 문자의 총 길이.
}				t_format;


extern	char	g_hex_b[17];
extern	char	g_hex_s[17];

void			exception_null(t_format *t_node, int num); //null출력 (.있고 pre = 0 값도 0)
void			p_exception_null(t_format *t_node, int num); // 0x빼고 null출력
void			negative_d(t_format *t_node, int num);
void			positive_d(t_format *t_node, int num);
void			n_judge_max(t_format *t_node);
void			init_zero(t_format *t_node);
void			check_null(t_format *t_node, char **str); //%s일 때 str에 (null)넣고 길이 6
void			pf_bzero(void *ptr, size_t size); //zero로 채워주는 함수.
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
