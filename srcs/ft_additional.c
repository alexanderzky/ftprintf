/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:29:35 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 22:04:48 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_format_len(const char **format)
{
	size_t i;

	i = 0;
	while (format[0][i] && format[0][i] != '%')
		i++;
	return (i);
}

void	ft_di_wps(t_params **ts, char **str, long di, long i)
{
	long j;

	j = 0;
	if (di < 0)
		(*ts)->ostr = ft_itoa(di * -1);
	i = (i - ft_strlen((*ts)->ostr)) + 1;
	while ((*ts)->ostr[j])
	{
		str[0][i++] = (*ts)->ostr[j++];
		(*ts)->p--;
	}
	i -= (di >= 0) ? ft_nbr_lngth(di) + 1 : ft_nbr_lngth(di);
	while ((*ts)->p--)
	{
		str[0][i--] = '0';
	}
	if ((*ts)->plus == 1)
		str[0][i--] = '+';
	else if ((*ts)->space == 1)
		str[0][i--] = ' ';
	else if (di < 0)
		str[0][i--] = '-';
	while (i >= 0)
		str[0][i--] = ' ';
}

void	ft_di_else(t_params **ts, char **str)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[0][i++] = '+';
	else if ((*ts)->space == 1)
		str[0][i++] = ' ';
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
}

long	ft_p_size(t_params **temp)
{
	long size;

	if ((*temp)->ostr[0] == '0' && (*temp)->p == 0)
		size = 0;
	else
		size = ft_strlen((*temp)->ostr);
	if ((*temp)->p > size || (*temp)->w > size)
	{
		if ((*temp)->w > (*temp)->p)
			size = (*temp)->w;
		else
			size = (*temp)->p;
	}
	if ((*temp)->w == ft_strlen((*temp)->ostr) + 1)
		size++;
	else if ((ft_strlen((*temp)->ostr) + 2 > size) || (*temp)->p == size)
		size += 2;
	return (size);
}
