/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:53:30 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 22:25:28 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_di_less(t_params **ts)
{
	(*ts)->plus = -1;
	(*ts)->space = -1;
}

long	ft_di_size(t_params **ts, long di)
{
	long size;

	size = ft_nbr_lngth(di);
	if (di == 0 && (*ts)->p == 0)
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
	if (((((*ts)->plus == 1 || (*ts)->space == 1) &&
		(((ft_nbr_lngth(di) + 1 > size)) || ((*ts)->p >= (*ts)->w &&
		(*ts)->p > ft_nbr_lngth(di)))) || (di < 0 && (*ts)->p >= (*ts)->w &&
			(*ts)->p > ft_nbr_lngth(di * -1))))
		size++;
	return (size);
}

void	ft_buffer_add_di(t_params **ts, long di)
{
	char *str;
	long size;

	if (di < 0)
		ft_di_less(ts);
	(*ts)->ostr = ft_itoa(di);
	size = ft_di_size(ts, di);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		(*ts)->error = 1;
	str[size] = '\0';
	if ((*ts)->minus == 1)
		ft_di_minus(ts, &str, size, di);
	else if ((*ts)->w > ft_nbr_lngth(di) && (*ts)->p <= ft_nbr_lngth(di))
		ft_di_wsp(ts, &str, di, size - 1);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_nbr_lngth(di) ||
			(*ts)->p > ft_nbr_lngth(di * -1)))
		ft_di_p(ts, &str, di, size - 1);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_nbr_lngth(di))
		ft_di_wps(ts, &str, di, size - 1);
	else
		ft_di_else(ts, &str);
	if (!(*ts)->error)
		(*ts)->counter += write(1, str, ft_strlen(str));
	free(str);
	free((*ts)->ostr);
}
