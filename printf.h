/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 06:37:18 by bndao             #+#    #+#             */
/*   Updated: 2016/02/08 21:09:27 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_data
{
	int				p_cent;
	char			*ante;
	char			*before;
	char			*after;
	char			o_minus;
	char			o_plus;
	char			o_diez;
	char			o_zero;
	char			o_space;
	int				width;
	int				precision;
	char			*length;
}					t_data;

typedef struct		s_conv
{
	char			s;
	char			S;
	char			p;
	char			d;
	char			D;
	char			i;
	char			o;
	char			O;
	char			u;
	char			U;
	char			x;
	char			X;
	char			c;
	char			C;
}					t_conv;

int					handle_no_p_cent(char *cpy);
int					handle_glued(t_data *t);
char				*ante_percent(char *fmt);
char				*post_percent(char *fmt);
char				*after_t_conv(char *fmt);
int					percent_nbr(char *fmt);
int					double_percent(char *fmt);
char				*before_t_conv(char *fmt);
int					is_b_t_conv(char *fmt, int *i);
char				return_char(char *fmt, char c);
t_data				*init(char *cpy);
t_conv				*init_conv(char *cpy);
int					handle_s(va_list conv, t_data *t, char *cpy);
int					handle_d(va_list conv, t_data *t, char *cpy);
int					handle_t_ante(t_data *t);
int					handle_t_after(t_data *t);
int					null_case(t_data *t);
int					handle(va_list conv, char *cpy, t_data *t, t_conv *c);

#endif
