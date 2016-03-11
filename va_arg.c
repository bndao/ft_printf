/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 21:45:13 by bndao             #+#    #+#             */
/*   Updated: 2016/03/11 23:11:34 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t				size_d(va_list conv, t_data *t, t_conv *c)
{
	intmax_t		nbr;

	nbr = 0;
	if ((!t->h && !t->hh && !t->l && !t->ll && !t->j && !t->z && !c->D) ||
			(t->hh && c->D))
		nbr = va_arg(conv, int);
	else if (t->h && c->D)
		nbr = va_arg(conv, long int);
	else if (t->h)
		nbr = (short)va_arg(conv, int);
	else if (t->hh)
		nbr = (char)va_arg(conv, int);
	else if (t->l || c->D)
		nbr = va_arg(conv, long int);
	else if (t->ll || t->j)
		nbr = va_arg(conv, intmax_t);
	else if (t->z)
		nbr = va_arg(conv, size_t);
	return (nbr);
}

uintmax_t				size_uoxX(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t		nbr;

	nbr = 0;
	if (!t->h && !t->hh && !t->l && !t->ll && !t->j && !t->z && !c->U && !c->O)
		nbr = va_arg(conv, unsigned int);
	else if (t->hh && c->U)
		nbr = (unsigned short int)va_arg(conv, unsigned int);
	else if (t->hh && c->O)
		nbr = (unsigned short int)va_arg(conv, unsigned int);
	else if (t->h && !(t->h && c->U))
		nbr = (unsigned short int)va_arg(conv, unsigned int);
	else if (t->hh)
		nbr = (unsigned char)va_arg(conv, unsigned int);
	else if (t->l || c->O || (t->h && c->U))
		nbr = va_arg(conv, unsigned long int);
	else if (t->ll || t->j || c->U)
		nbr = va_arg(conv, uintmax_t);
	else if (t->z)
		nbr = va_arg(conv, size_t);
	return (nbr);
}
