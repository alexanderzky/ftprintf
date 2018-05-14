/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_additional.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:10:05 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 18:53:19 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long	ft_di_zero(t_params **ts, long i)
{
	if ((*ts)->dminus)
	{
		while (i > 0)
		{
			(*ts)->astr[i--] = '0';
			(*ts)->w--;
		}
		(*ts)->astr[i] = '-';
		(*ts)->w--;
	}
	else if ((*ts)->plus == 1 || (*ts)->space == 1)
	{
		while (i > 0)
			(*ts)->astr[i--] = '0';
		(*ts)->astr[i--] = ((*ts)->plus == 1) ? '+' : ' ';
	}
	else
		while (i >= 0)
			(*ts)->astr[i--] = '0';
	return (i);
}

long	ft_di_putchar(t_params **ts, long i)
{
	if ((*ts)->plus == 1)
	{
		(*ts)->astr[i--] = '+';
		(*ts)->w--;
	}
	if ((*ts)->dminus)
	{
		(*ts)->astr[i--] = '-';
		(*ts)->w--;
		(*ts)->dminus = 0;
	}
	if ((*ts)->space == 1)
	{
		(*ts)->astr[i--] = ' ';
		(*ts)->w--;
	}
	return (i);
}

long	ft_di_ostr_copy(t_params **ts, long i)
{
	long j;

	j = ft_strlen((*ts)->ostr) - 1;
	while (j >= 0)
	{
		(*ts)->astr[i] = (*ts)->ostr[j];
		i--;
		j--;
		(*ts)->w--;
		(*ts)->p--;
	}
	return (i);
}

void	ft_di_wsp(t_params **ts, long i)
{
	i = ft_di_ostr_copy(ts, i);
	if ((*ts)->zero == 1)
		i = ft_di_zero(ts, i);
	else if ((*ts)->p > 0)
	{
		(*ts)->astr[i--] = '0';
		(*ts)->p--;
		(*ts)->w--;
	}
	i = ft_di_putchar(ts, i);
	while ((*ts)->w > 0 && i >= 0)
	{
		(*ts)->astr[i--] = ' ';
		(*ts)->w--;
	}
	if ((*ts)->dminus)
		(*ts)->astr[0] = '-';
}

void	ft_di_p(t_params **ts, long i)
{
	long j;

	j = 0;
	i = (i - ft_strlen((*ts)->ostr)) + 1;
	while ((*ts)->ostr[j])
		(*ts)->astr[i++] = (*ts)->ostr[j++];
	i -= ((*ts)->dminus) ? ft_sl_d((*ts)->ostr, ts) :
		ft_strlen((*ts)->ostr) + 1;
	while (i > 0)
		(*ts)->astr[i--] = '0';
	if ((*ts)->plus == 1)
		(*ts)->astr[i] = '+';
	else if ((*ts)->space == 1)
		(*ts)->astr[i] = ' ';
	else if ((*ts)->dminus)
		(*ts)->astr[i] = '-';
	else
		(*ts)->astr[i] = '0';
}
