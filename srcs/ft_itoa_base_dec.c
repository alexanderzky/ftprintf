/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:49:12 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 18:52:43 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_huge_numb(char **str, long value, long size, t_params **temp)
{
	static char		val[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
								'9'};
	unsigned long	uvalue;
	long			i;
	long			j;

	(*temp)->dminus = 1;
	uvalue = (unsigned long)(value * -1);
	size = ft_nbr_lngth(uvalue);
	if (!(str[0] = (char*)malloc(sizeof(char) * (size + 1))))
		return ;
	str[0][size] = '\0';
	i = size - 1;
	while (uvalue)
	{
		j = uvalue % 10;
		str[0][i] = val[j];
		uvalue = uvalue / 10;
		i--;
	}
}

void	ft_numb(char **str, long value, long size)
{
	static char	val[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	long		i;
	long		j;

	size = ft_nbr_lngth(value);
	if (!(str[0] = (char*)malloc(sizeof(char) * (size + 1))))
		return ;
	str[0][size] = '\0';
	i = size - 1;
	while (value)
	{
		j = value % 10;
		str[0][i] = val[j];
		value = value / 10;
		i--;
	}
}

char	*ft_itoa_base_dec(long value, t_params **temp)
{
	long		size;
	char		*str;

	size = 0;
	if (value == 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (2))))
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (value < 0)
		ft_huge_numb(&str, value, size, temp);
	else
		ft_numb(&str, value, size);
	return (str);
}
