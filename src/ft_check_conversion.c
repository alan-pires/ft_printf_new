/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:00:11 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 15:19:05 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_conversion(const char *format, va_list args, t_option *opt)
{
	if (format[opt->posit] == 'c')
		ft_printf_char(args, opt);
	else if (format[opt->posit] == 's')
		ft_printf_str(args, opt);
	else if (format[opt->posit] == 'd' || format[opt->posit] == 'i')
		ft_printf_int(args, opt);
	else if (format[opt->posit] == 'u')
		ft_printf_unsi_int(args, opt);
	else if (format[opt->posit] == 'x')
	{
		opt->hexa = 'x';
		ft_printf_unsi_hex(args, opt);
	}
	else if (format[opt->posit] == 'X')
	{
		opt->hexa = 'X';
		ft_printf_unsi_hex(args, opt);
	}
	else if (format[opt->posit] == 'p')
		ft_printf_point(args, opt);
	else if (format[opt->posit] == '%')
		ft_printf_percent(opt);
	opt->posit++;
}
