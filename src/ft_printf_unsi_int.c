/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsi_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:51:54 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 01:03:09 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_unsi_count(unsigned int n, t_option *opt)
{
	unsigned int	num;

	num = n;
	if (num >= 10)
		ft_put_unsi_count(num / 10, opt);
	ft_putchar_count((char)(num % 10 + '0'), opt);
}

void	ft_printf_unsi_int(va_list args, t_option *opt)
{
	unsigned int	uint_arg;

	uint_arg = va_arg(args, unsigned int);
	ft_put_unsi_count(uint_arg, opt);
	ft_reset_opt(opt);
}
