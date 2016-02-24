/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:26 by bndao             #+#    #+#             */
/*   Updated: 2016/02/24 21:45:56 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						handle_width(int len_conv, t_data *t)
{
	int			i;
	char		c;

	c = ' ';
	if (t->o_zero)
		c = '0';
	i = t->width - len_conv;
	if (i <= 0)
		return (0);
	while (i)
	{
		ft_putchar(c);
		i--;
	}
	return (t->width - len_conv);
}

int						handle_width_d(int len_conv, t_data *t, int d)
{
	int			i;
	char		c;
	char		ok;

	c = ' ';
	ok = 0;
	if (t->o_zero)
		c = '0';
	if (d < 0 && t->o_zero)
	{
		ok = 1;
		ft_putchar('-');
	}
	i = t->width - len_conv;
	if (i <= 0)
		return (0);
	while (i--)
		ft_putchar(c);
	if (t->o_zero && d < 0)
	{
		d = -d;
		ft_putnbr(d);
	}
	return (t->width - len_conv + ok);
}

int					handle_o_zero_d(int d, t_data *t)
{
	if (t->o_zero && d < 0)
	{
		d = -d;
		return (ft_strlen(ft_itoa(d)));
	}
	else
		ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

int					handle_o_space(int d, t_data *t)
{
	int			ret;

	ret = 0;
	if (d >= 0 && !t->o_plus && t->o_space)
	{
		ft_putchar(' ');
		ret = 1;
	}
	return (ret);
}
