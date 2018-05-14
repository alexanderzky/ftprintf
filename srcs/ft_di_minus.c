/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:56:22 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 18:49:11 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_di_minus_wsp(t_params **ts, char **str, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[0][i++] = '+';
	else if ((*ts)->space == 1)
		str[0][i++] = ' ';
	if ((*ts)->dminus)
	{
		str[0][0] = '-';
		(*ts)->dminus = 0;
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

void	ft_di_minus_pw(t_params **ts, char **str, long size)
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
	if ((*ts)->dminus)
	{
		str[0][0] = '-';
		(*ts)->dminus = 0;
	}
	else if ((*ts)->plus == 1)
		str[0][0] = '+';
	else if ((*ts)->space == 1)
		str[0][0] = ' ';
	i = size - ft_sl_d((*ts)->ostr, ts);
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
}

void	ft_di_minus_pws(t_params **ts, char **str, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[0][i++] = '+';
	else if ((*ts)->space == 1)
		str[0][i++] = ' ';
	if ((*ts)->dminus)
	{
		str[0][i++] = '-';
		(*ts)->dminus = 0;
	}
	while (j < (*ts)->p - ft_sl_d((*ts)->ostr, ts))
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

void	ft_di_minus(t_params **ts, char **str, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[0][i++] = '+';
	else if ((*ts)->space == 1)
		str[0][i++] = ' ';
	else if ((*ts)->dminus)
		str[0][i++] = '-';
	if ((*ts)->w > ft_sl_d((*ts)->ostr, ts) && (*ts)->p <=
			ft_sl_d((*ts)->ostr, ts))
		ft_di_minus_wsp(ts, str, size);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_sl_d((*ts)->ostr, ts)
					|| (*ts)->p > ft_strlen((*ts)->ostr)))
		ft_di_minus_pw(ts, str, size);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_sl_d((*ts)->ostr, ts))
		ft_di_minus_pws(ts, str, size);
	else
		while ((*ts)->ostr[j])
			str[0][i++] = (*ts)->ostr[j++];
}
