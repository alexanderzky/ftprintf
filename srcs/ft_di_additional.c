/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_additional.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:10:05 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 18:51:47 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long	ft_di_zero(t_params **ts, char **str, long i)
{
	if ((*ts)->dminus)
	{
		while (i > 0)
		{
			str[0][i--] = '0';
			(*ts)->w--;
		}
		str[0][i] = '-';
		(*ts)->w--;
	}
	else if ((*ts)->plus == 1 || (*ts)->space == 1)
	{
		while (i > 0)
			str[0][i--] = '0';
		str[0][i--] = ((*ts)->plus == 1) ? '+' : ' ';
	}
	else
		while (i >= 0)
			str[0][i--] = '0';
	return (i);
}

long	ft_di_putchar(t_params **ts, char **str, long i)
{
	if ((*ts)->plus == 1)
	{
		str[0][i--] = '+';
		(*ts)->w--;
	}
	if ((*ts)->dminus)
	{
		str[0][i--] = '-';
		(*ts)->w--;
		(*ts)->dminus = 0;
	}
	if ((*ts)->space == 1)
	{
		str[0][i--] = ' ';
		(*ts)->w--;
	}
	return (i);
}

long	ft_di_ostr_copy(t_params **ts, char **str, long i)
{
	long j;

	j = ft_strlen((*ts)->ostr) - 1;
	while (j >= 0)
	{
		str[0][i] = (*ts)->ostr[j];
		i--;
		j--;
		(*ts)->w--;
		(*ts)->p--;
	}
	return (i);
}

void	ft_di_wsp(t_params **ts, char **str, long i)
{
	i = ft_di_ostr_copy(ts, str, i);
	if ((*ts)->zero == 1)
		i = ft_di_zero(ts, str, i);
	else if ((*ts)->p > 0)
	{
		str[0][i--] = '0';
		(*ts)->p--;
		(*ts)->w--;
	}
	i = ft_di_putchar(ts, str, i);
	while ((*ts)->w > 0 && i >= 0)
	{
		str[0][i--] = ' ';
		(*ts)->w--;
	}
	if ((*ts)->dminus)
		str[0][0] = '-';
}

void	ft_di_p(t_params **ts, char **str, long i)
{
	long j;

	j = 0;
	i = (i - ft_strlen((*ts)->ostr)) + 1;
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
	i -= ((*ts)->dminus) ? ft_sl_d((*ts)->ostr, ts) :
		ft_strlen((*ts)->ostr) + 1;
	while (i > 0)
		str[0][i--] = '0';
	if ((*ts)->plus == 1)
		str[0][i] = '+';
	else if ((*ts)->space == 1)
		str[0][i] = ' ';
	else if ((*ts)->dminus)
		str[0][i] = '-';
	else
		str[0][i] = '0';
}
