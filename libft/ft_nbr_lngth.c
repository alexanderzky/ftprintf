/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_lngth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:11:17 by ozalisky          #+#    #+#             */
/*   Updated: 2018/04/28 16:50:24 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nbr_lngth(long n)
{
	unsigned long un;

	if (n >= 0 && n <= 9)
		return (1);
	if (n > -10 && n < 0)
	{
		return (2);
	}
	if (n < 0)
	{
		un = (unsigned long)(n * -1);
		return (2 + ft_nbr_lngth(un / 10));
	}
	if (n / 10 != 0)
		return (1 + ft_nbr_lngth(n / 10));
	return (0);
}
