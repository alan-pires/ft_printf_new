/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:51:28 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 00:44:43 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	check_conv_err(t_option *opt, char conv)
{
	int	error;

	error = 0;
	if (opt->zero > 0 && opt->prec > -1)
		error = 1;
	if (conv == 'c' && (opt->zero != 0 || opt->prec != -1))
		error = 1;
	if (conv == 's' && opt->zero != 0)
		error = 1;
	opt->posit++;
	return (error);
}

int	ft_check_errors(const char *format, t_option *opt )
{
	int		is_err;

	is_err = 0;
	while (format[opt->posit])
	{
		if (format[opt->posit] == '%')
		{
			ft_check_flags(format, opt);
			is_err = check_conv_err(opt, format[opt->posit]);
			ft_reset_opt(opt);
			return (is_err);
		}
		else
			opt->posit++;
	}
	return (0);
}
