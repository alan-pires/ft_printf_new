/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:58:52 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 15:02:44 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_option	opt;

	init_options(&opt);
	va_start(args, format);
	while (format[opt.posit])
	{
		if (format[opt.posit] == '%')
		{
			opt.posit++;
			ft_check_conversion(format, args, &opt);
		}
		else
			ft_putchar_count(format[opt.posit++], &opt);
	}
	va_end(args);
	return (opt.count);
}
