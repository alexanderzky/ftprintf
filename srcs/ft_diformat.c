/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:53:30 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 18:43:39 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_di_less(t_params **ts)
{
	(*ts)->plus = -1;
	(*ts)->space = -1;
}

long	ft_sl_d(const char *s, t_params **ts)
{
	long string_i;

	string_i = 0;
	while (s[string_i])
	{
		string_i++;
	}
	if ((*ts)->dminus)
		string_i++;
	return (string_i);
}

long	ft_di_size(t_params **ts)
{
	long size;

	size = ft_sl_d((*ts)->ostr, ts);
	if ((*ts)->ostr[0] == '0' && (*ts)->p == 0)
	{
		(*ts)->ostr[0] = '\0';
		size = 0;
	}
	if ((*ts)->p > size || (*ts)->w > size)
	{
		if ((*ts)->w > (*ts)->p)
			size = (*ts)->w;
		else
			size = (*ts)->p;
	}
	if ((((*ts)->plus == 1 || (*ts)->space == 1) &&
		(((ft_sl_d((*ts)->ostr, ts) + 1 > size)) ||
		((*ts)->p >= (*ts)->w && (*ts)->p > ft_sl_d((*ts)->ostr, ts)))) ||
		((*ts)->dminus && (*ts)->p >= (*ts)->w && (*ts)->p >
													ft_strlen((*ts)->ostr)))
		size++;
	return (size);
}

int		ft_flcmp(t_params **ts)
{
	if ((*ts)->w > ft_sl_d((*ts)->ostr, ts) && (*ts)->p <=
													ft_sl_d((*ts)->ostr, ts))
		return (1);
	return (0);
}

void	ft_buffer_add_di(t_params **ts, char *di)
{
	char *str;
	long size;

	(*ts)->ostr = di;
	if ((*ts)->dminus)
		ft_di_less(ts);
	size = ft_di_size(ts);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		(*ts)->error = 1;
	str[size] = '\0';
	if ((*ts)->minus == 1)
		ft_di_minus(ts, &str, size);
	else if (ft_flcmp(ts))
		ft_di_wsp(ts, &str, size - 1);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_sl_d((*ts)->ostr, ts) ||
			(*ts)->p > ft_strlen((*ts)->ostr)))
		ft_di_p(ts, &str, size - 1);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_sl_d((*ts)->ostr, ts))
		ft_di_wps(ts, &str, size - 1, 0);
	else
		ft_di_else(ts, &str);
	if (!(*ts)->error)
		(*ts)->counter += write(1, str, ft_strlen(str));
	free(str);
}
