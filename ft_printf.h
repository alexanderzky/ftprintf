/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:18:08 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/15 17:13:27 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

typedef struct	s_params
{
	short		minus;
	short		plus;
	short		space;
	short		hash;
	short		zero;
	long		w;
	long		p;
	int			x;
	int			length;
	int			skip;
	char		type;
	ssize_t		counter;
	long		meter;
	char		*ostr;
	int			freeme;
	int			error;
	int			dminus;
}				t_params;

size_t			ft_format_len(const char **format);
t_params		*ft_create_specs();
void			ft_clean_params(t_params **temp);
char			*ft_itoa_base(unsigned long value, int base, int i);
long			ft_strsimplelen(const wchar_t *s);
void			ft_buffer_add_wrong(t_params **temp, const char **s);
int				ft_type_ch(const char **format);
int				ft_prec_ch(const char **format);
int				ft_width_ch(const char **format);
int				ft_length_ch(const char **format);
int				ft_flag_ch(const char *format);
void			ft_flag_add(t_params **temp, const char **format);
void			ft_width_add(t_params **temp, const char **format, va_list vl);
void			ft_prec_add(t_params **temp, const char **format, va_list vl);
void			ft_length_add(t_params **temp, const char **format);
void			ft_type_add(t_params **temp, const char **format);
void			ft_length_influence_p(t_params **temp, unsigned long xx);
void			ft_length_influence_c(t_params **temp, unsigned int c);
void			ft_length_influence_s(t_params **temp, char *s);
void			ft_buffer_add_ws(t_params **ts, wchar_t *s);
void			ft_length_influence_di(t_params **temp, long di);
void			ft_length_influence_o(t_params **temp, unsigned long o);
void			ft_length_influence_u(t_params **temp, unsigned long u);
void			ft_length_influence_xx(t_params **temp, unsigned long xx);
void			ft_length_influence_b(t_params **temp, unsigned long b);
long			ft_u_size_forbuffer_add(t_params **temp);
void			ft_u_minus_wps(t_params **temp, char **str, long size);
void			ft_u_minus(t_params **ts, char **str, long size);
void			ft_buffer_add_o(t_params **temp, char *ostr);
void			ft_buffer_add_u(t_params **ts, char *ostr);
void			ft_buffer_add_xx(t_params **ts, char *xx);
void			ft_buffer_add_di(t_params **ts, long size);
void			ft_buffer_add_p(t_params **ts, char *di_char);
void			ft_buffer_add_s(t_params **ts, char *s);
void			ft_buffer_add_c(t_params **temp, unsigned char di);
void			ft_buffer_add_wc(t_params **temp, wchar_t c);
void			ft_buffer_wc(t_params **temp, wchar_t c);
int				ft_printf(const char *format, ...);
void			ft_0_wsp(t_params **temp, char **str, long size, long i);
void			ft_0_wps(t_params **temp, char **str, long size, long i);
void			ft_o_minus(t_params **ts, char **str, long size);
void			ft_o_wsp(t_params **temp, char **str, long i, long j);
long			ft_p_size(t_params **temp);
void			ft_p_minus_wsp(t_params **temp, char **str, long size, long i);
void			ft_p_minus_ps(t_params **temp, char **str, long size, long i);
void			ft_p_minus_wps(t_params **temp, char **str, long size, long i);
void			ft_p_minus(t_params **ts, char **str, long size);
void			ft_p_wsp(t_params **temp, char **str, long i);
void			ft_di_minus(t_params **ts, long size, char *str);
void			ft_di_wsp(t_params **ts, long i, char *str);
void			ft_di_p(t_params **ts, long i, char *str);
void			ft_di_wps(t_params **ts, long i, long j, char *str);
void			ft_di_else(t_params **ts, char *str);
void			ft_di_less(t_params **ts);
long			ft_precstrlen(t_params **temp, wchar_t *str);
long			ft_precwidstrlen(t_params **temp, wchar_t *str);
void			ft_buffer_add_ws(t_params **ts, wchar_t *s);
void			ft_ws_minus(t_params **ts, wchar_t **str, wchar_t *s,
							long size);
void			ft_ws_plus(t_params **ts, wchar_t **str, wchar_t *s, long size);
void			ft_ws_plus_0(t_params **ts, wchar_t **str, long size);
void			ft_s_plus(t_params **ts, char **str, char *s, long size);
void			ft_x_p(t_params **ts, char **str, long i);
void			ft_x_0(t_params **ts, char **str, long i);
void			ft_x_wpd(t_params **ts, char **str, long i);
void			ft_x_x(char **str, long i);
void			ft_x_free(char *di_char, char *str);
void			ft_x_minus(t_params **ts, char **str, char *di_char, long size);
void			ft_itoa_base_dec(long value, t_params **temp);
long			ft_sl_d(const char *s, t_params **ts);
long			ft_di_size(t_params **ts);
#endif
