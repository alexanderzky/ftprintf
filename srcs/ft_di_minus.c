/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:56:22 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 18:50:21 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_di_less(t_params **ts)
{
	(*ts)->plus = -1;
	(*ts)->space = -1;
}

void	ft_di_minus_wsp(t_params **ts, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		(*ts)->astr[i++] = '+';
	else if ((*ts)->space == 1)
		(*ts)->astr[i++] = ' ';
	if ((*ts)->dminus)
	{
		(*ts)->astr[0] = '-';
		(*ts)->dminus = 0;
		i++;
	}
	while (ft_strlen((*ts)->ostr) < (*ts)->p)
	{
		(*ts)->astr[i++] = '0';
		(*ts)->p--;
	}
	while ((*ts)->ostr[j])
		(*ts)->astr[i++] = (*ts)->ostr[j++];
	while (i < size)
		(*ts)->astr[i++] = ' ';
}

void	ft_di_minus_pw(t_params **ts, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		(*ts)->astr[i++] = '+';
	else if ((*ts)->space == 1)
		(*ts)->astr[i++] = ' ';
	while (i < size)
		(*ts)->astr[i++] = '0';
	if ((*ts)->dminus)
	{
		(*ts)->astr[0] = '-';
		(*ts)->dminus = 0;
	}
	else if ((*ts)->plus == 1)
		(*ts)->astr[0] = '+';
	else if ((*ts)->space == 1)
		(*ts)->astr[0] = ' ';
	i = size - ft_sl_d((*ts)->ostr, ts);
	while ((*ts)->ostr[j])
		(*ts)->astr[i++] = (*ts)->ostr[j++];
}

void	ft_di_minus_pws(t_params **ts, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		(*ts)->astr[i++] = '+';
	else if ((*ts)->space == 1)
		(*ts)->astr[i++] = ' ';
	if ((*ts)->dminus)
	{
		(*ts)->astr[i++] = '-';
		(*ts)->dminus = 0;
	}
	while (j < (*ts)->p - ft_sl_d((*ts)->ostr, ts))
	{
		(*ts)->astr[i] = '0';
		i++;
		j++;
	}
	j = 0;
	while ((*ts)->ostr[j])
		(*ts)->astr[i++] = (*ts)->ostr[j++];
	while (i < size)
		(*ts)->astr[i++] = ' ';
}

void	ft_di_minus(t_params **ts, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		(*ts)->astr[i++] = '+';
	else if ((*ts)->space == 1)
		(*ts)->astr[i++] = ' ';
	else if ((*ts)->dminus)
		(*ts)->astr[i++] = '-';
	if ((*ts)->w > ft_sl_d((*ts)->ostr, ts) && (*ts)->p <=
			ft_sl_d((*ts)->ostr, ts))
		ft_di_minus_wsp(ts, size);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_sl_d((*ts)->ostr, ts)
					|| (*ts)->p > ft_strlen((*ts)->ostr)))
		ft_di_minus_pw(ts, size);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_sl_d((*ts)->ostr, ts))
		ft_di_minus_pws(ts, size);
	else
		while ((*ts)->ostr[j])
			(*ts)->astr[i++] = (*ts)->ostr[j++];
}
