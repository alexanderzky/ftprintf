/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:56:22 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 18:08:48 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_di_minus_wsp(t_params **ts, char **str, long size, long di)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[0][i++] = '+';
	else if ((*ts)->space == 1)
		str[0][i++] = ' ';
	if (di < 0)
	{
		str[0][0] = '-';
		(*ts)->ostr = ft_itoa(di * -1);
		i++;
	}
	while (ft_strlen((*ts)->ostr) < (*ts)->p)
	{
		str[0][i++] = '0';
		(*ts)->p--;
	}
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_di_minus_pw(t_params **ts, char **str, long size, long di)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[0][i++] = '+';
	else if ((*ts)->space == 1)
		str[0][i++] = ' ';
	while (i < size)
		str[0][i++] = '0';
	if (di < 0)
	{
		str[0][0] = '-';
		(*ts)->ostr = ft_itoa(di * -1);
	}
	else if ((*ts)->plus == 1)
		str[0][0] = '+';
	else if ((*ts)->space == 1)
		str[0][0] = ' ';
	i = size - ft_strlen((*ts)->ostr);
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
}

void	ft_di_minus_pws(t_params **ts, char **str, long size, long di)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[0][i++] = '+';
	else if ((*ts)->space == 1)
		str[0][i++] = ' ';
	if (di < 0)
		str[0][i++] = '-';
	if (di < 0)
		(*ts)->ostr = ft_itoa(di * -1);
	while (j < (*ts)->p - ft_strlen((*ts)->ostr))
	{
		str[0][i] = '0';
		i++;
		j++;
	}
	j = 0;
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_di_minus(t_params **ts, char **str, long size, long di)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[0][i++] = '+';
	else if ((*ts)->space == 1)
		str[0][i++] = ' ';
	if ((*ts)->w > ft_nbr_lngth(di) && (*ts)->p <= ft_nbr_lngth(di))
		ft_di_minus_wsp(ts, str, size, di);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_nbr_lngth(di) ||
			(*ts)->p > ft_nbr_lngth(di * -1)))
		ft_di_minus_pw(ts, str, size, di);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_nbr_lngth(di))
		ft_di_minus_pws(ts, str, size, di);
	else
		while ((*ts)->ostr[j])
			str[0][i++] = (*ts)->ostr[j++];
}
