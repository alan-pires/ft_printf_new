/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:58:52 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 00:37:58 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_option	opt;

	init_options(&opt);
	if (ft_check_errors(format, &opt) == 1)
		return (-1);
	va_start(args, format);
	init_options(&opt);
	while (format[opt.posit])
	{
		if (format[opt.posit] == '%')
		{
			opt.posit++;
			ft_check_flags(format, &opt);
			ft_send_format(format, args, &opt);
		}
		else
			ft_putchar_count(format[opt.posit++], &opt);
	}
	va_end(args);
	return (opt.count);
}
