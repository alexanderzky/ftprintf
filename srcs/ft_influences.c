/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_influences.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:42:53 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/15 15:25:20 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_length_influence_di(t_params **ts, long di)
{
	long size;

	if ((*ts)->length == -1)
		ft_itoa_base_dec((int)di, ts);
	else if ((*ts)->length == 0)
		ft_itoa_base_dec((signed char)di, ts);
	else if ((*ts)->length == 1)
		ft_itoa_base_dec((short)di, ts);
	else if ((*ts)->length == 2)
		ft_itoa_base_dec(di, ts);
	else if ((*ts)->length == 3)
		ft_itoa_base_dec((long long)di, ts);
	else if ((*ts)->length == 4)
		ft_itoa_base_dec((ssize_t)di, ts);
	else if ((*ts)->length == 5)
		ft_itoa_base_dec((intmax_t)di, ts);
	size = ft_di_size(ts);
	ft_buffer_add_di(ts, size);
}

void	ft_length_influence_o(t_params **temp, unsigned long o)
{
	if ((*temp)->length == -1)
		ft_buffer_add_o(temp, ft_itoa_base((unsigned int)o, 8, 0));
	else if ((*temp)->length == 0)
		ft_buffer_add_o(temp, ft_itoa_base((unsigned char)o, 8, 0));
	else if ((*temp)->length == 1)
		ft_buffer_add_o(temp, ft_itoa_base((unsigned short)o, 8, 0));
	else if ((*temp)->length == 2)
		ft_buffer_add_o(temp, ft_itoa_base(o, 8, 0));
	else if ((*temp)->length == 3)
		ft_buffer_add_o(temp, ft_itoa_base((unsigned long long)o, 8, 0));
	else if ((*temp)->length == 4)
		ft_buffer_add_o(temp, ft_itoa_base((size_t)o, 8, 0));
	else if ((*temp)->length == 5)
		ft_buffer_add_o(temp, ft_itoa_base((uintmax_t)o, 8, 0));
}

void	ft_length_influence_u(t_params **temp, unsigned long u)
{
	if ((*temp)->length == -1)
		ft_buffer_add_u(temp, ft_itoa_base((unsigned int)u, 10, 0));
	else if ((*temp)->length == 0)
		ft_buffer_add_u(temp, ft_itoa_base((unsigned char)u, 10, 0));
	else if ((*temp)->length == 1)
		ft_buffer_add_u(temp, ft_itoa_base((unsigned short)u, 10, 0));
	else if ((*temp)->length == 2)
		ft_buffer_add_u(temp, ft_itoa_base(u, 10, 0));
	else if ((*temp)->length == 3)
		ft_buffer_add_u(temp, ft_itoa_base((unsigned long long)u, 10, 0));
	else if ((*temp)->length == 4)
		ft_buffer_add_u(temp, ft_itoa_base((size_t)u, 10, 0));
	else if ((*temp)->length == 5)
		ft_buffer_add_u(temp, ft_itoa_base((uintmax_t)u, 10, 0));
}

void	ft_length_influence_xx(t_params **temp, unsigned long xx)
{
	if ((*temp)->length == -1)
		ft_buffer_add_xx(temp, ft_itoa_base((unsigned int)xx, 16, 0));
	else if ((*temp)->length == 0)
		ft_buffer_add_xx(temp, ft_itoa_base((unsigned char)xx, 16, 0));
	else if ((*temp)->length == 1)
		ft_buffer_add_xx(temp, ft_itoa_base((unsigned short)xx, 16, 0));
	else if ((*temp)->length == 2)
		ft_buffer_add_xx(temp, ft_itoa_base(xx, 16, 0));
	else if ((*temp)->length == 3)
		ft_buffer_add_xx(temp, ft_itoa_base((unsigned long long)xx, 16, 0));
	else if ((*temp)->length == 4)
		ft_buffer_add_xx(temp, ft_itoa_base((size_t)xx, 16, 0));
	else if ((*temp)->length == 5)
		ft_buffer_add_xx(temp, ft_itoa_base((uintmax_t)xx, 16, 0));
}

void	ft_length_influence_b(t_params **temp, unsigned long b)
{
	if ((*temp)->length == -1)
		ft_buffer_add_o(temp, ft_itoa_base((unsigned int)b, 2, 0));
	else if ((*temp)->length == 0)
		ft_buffer_add_o(temp, ft_itoa_base((unsigned char)b, 2, 0));
	else if ((*temp)->length == 1)
		ft_buffer_add_o(temp, ft_itoa_base((unsigned short)b, 2, 0));
	else if ((*temp)->length == 2)
		ft_buffer_add_o(temp, ft_itoa_base(b, 2, 0));
	else if ((*temp)->length == 3)
		ft_buffer_add_o(temp, ft_itoa_base((unsigned long long)b, 2, 0));
	else if ((*temp)->length == 4)
		ft_buffer_add_o(temp, ft_itoa_base((size_t)b, 2, 0));
	else if ((*temp)->length == 5)
		ft_buffer_add_o(temp, ft_itoa_base((uintmax_t)b, 2, 0));
}
