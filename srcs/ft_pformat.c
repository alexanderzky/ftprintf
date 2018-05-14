/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:34:26 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 22:20:45 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_p_ps(t_params **temp, char **str, long i)
{
	long j;

	i = (i - ft_strlen((*temp)->ostr)) + 1;
	j = 0;
	while ((*temp)->ostr[j])
		str[0][i++] = (*temp)->ostr[j++];
	i -= j + 1;
	while (i >= 0)
		str[0][i--] = '0';
	str[0][1] = 'x';
}

void	ft_p_wps(t_params **temp, char **str, long i)
{
	long j;
	long z;

	j = 0;
	i = (i - ft_strlen((*temp)->ostr)) + 1;
	z = i - 1;
	while ((*temp)->ostr[j])
	{
		str[0][i++] = (*temp)->ostr[j++];
		(*temp)->p--;
	}
	i = z;
	while ((*temp)->p--)
		str[0][i--] = '0';
	str[0][i--] = 'x';
	str[0][i--] = '0';
	while (i >= 0)
		str[0][i--] = ' ';
}

void	ft_p_zero(char **str)
{
	long i;

	i = 0;
	str[0][i++] = '0';
	str[0][i] = 'x';
}

void	ft_p_else(t_params **temp, char **str)
{
	long i;
	long j;

	j = 0;
	i = 0;
	str[0][i++] = '0';
	str[0][i++] = 'x';
	while ((*temp)->ostr[j])
		str[0][i++] = (*temp)->ostr[j++];
}

void	ft_buffer_add_p(t_params **ts, char *ostr)
{
	char *str;
	long size;

	(*ts)->ostr = ostr;
	size = ft_p_size(ts);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		(*ts)->error = 1;
	str[size] = '\0';
	if ((*ts)->minus == 1)
		ft_p_minus(ts, &str, size);
	else if ((*ts)->w > (int)ft_strlen((*ts)->ostr) &&
			(*ts)->p <= (int)ft_strlen((*ts)->ostr))
		ft_p_wsp(ts, &str, size - 1);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > (int)ft_strlen((*ts)->ostr)))
		ft_p_ps(ts, &str, size - 1);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > (int)ft_strlen((*ts)->ostr))
		ft_p_wps(ts, &str, size - 1);
	else if ((*ts)->ostr[0] == '0' && (*ts)->p == 0)
		ft_p_zero(&str);
	else
		ft_p_else(ts, &str);
	if (!(*ts)->error)
		(*ts)->counter += write(1, str, (size_t)ft_strlen(str));
	// free((*ts)->ostr);
	// free(str);
}
