/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:14:10 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 14:50:13 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_int(va_list args, t_option *opt)
{
	int	int_arg;

	int_arg = va_arg(args, int);
	if (int_arg >= 0)
		ft_putnbr_count(int_arg, opt);
	else
	{
		ft_putchar_count('-', opt);
		ft_putnbr_count(int_arg, opt);
	}
}
