/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:48:56 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 14:44:12 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_flag_add(t_params **temp, const char **format)
{
	if (**format == '-')
		(*temp)->minus = 1;
	else if (**format == '+')
		(*temp)->plus = 1;
	else if (**format == ' ')
		(*temp)->space = 1;
	else if (**format == '#')
		(*temp)->hash = 1;
	else if (**format == '0')
		(*temp)->zero = 1;
}

void		ft_width_add(t_params **temp, const char **format, va_list vl)
{
	int len;
	int wildcard;

	if (**format == 42)
	{
		wildcard = va_arg(vl, int);
		if (wildcard < 0)
		{
			(*temp)->minus = 1;
			wildcard *= -1;
		}
		(*temp)->w = wildcard;
	}
	else
	{
		(*temp)->w = ft_atoi(*format);
		len = ft_nbr_lngth(ft_atoi(*format));
		*format += len - 1;
	}
}

void		ft_prec_add(t_params **temp, const char **format, va_list vl)
{
	int len;
	int wildcard;

	if (*(*format + 1) > 47 && *(*format + 1) < 58)
	{
		*format += 1;
		(*temp)->p = ft_atoi(*format);
		len = ft_nbr_lngth(ft_atoi(*format));
		*format += len - 1;
	}
	else if (*(*format + 1) == 42)
	{
		wildcard = va_arg(vl, int);
		if (wildcard < 0)
			(*temp)->p = -1;
		else
			(*temp)->p = wildcard;
		*format += 1;
	}
	else
		(*temp)->p = 0;
}

void		ft_length_add(t_params **temp, const char **format)
{
	if (**format == 'h' && (*temp)->length < 2)
	{
		if ((*temp)->length == -1)
			(*temp)->length = 1;
		else if ((*temp)->length == 0)
			(*temp)->length = 1;
		else if ((*temp)->length == 1)
			(*temp)->length = 0;
	}
	else if (**format == 'l' && (*(*format + 1)) == 'l' && (*temp)->length < 3)
		(*temp)->length = 3;
	else if (**format == 'l' && (*temp)->length < 2)
		(*temp)->length = 2;
	else if (**format == 'j' && (*temp)->length < 5)
		(*temp)->length = 5;
	else if (**format == 'z' && (*temp)->length < 4)
		(*temp)->length = 4;
	if ((*temp)->length == 3)
		(*format)++;
}

void		ft_type_add(t_params **temp, const char **format)
{
	if (**format == 'D' || **format == 'O' || **format == 'U' ||
		**format == 'C' || **format == 'S' || **format == 'B')
	{
		(*temp)->length = 2;
		(*temp)->type = (**format + 32);
	}
	else if (**format == 'X')
	{
		(*temp)->type = 'x';
		(*temp)->x = 1;
	}
	else
		(*temp)->type = **format;
}
