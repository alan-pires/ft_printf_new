/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:47:22 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 13:19:22 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	print_wi_dash_char(va_list args, t_option *opt)
{
	int	char_arg;

	char_arg = va_arg(args, int);
	ft_putchar_count(char_arg, opt);
	while (opt->wid-- > 1)
		ft_putchar_count(' ', opt);
}

static void	print_wi_char(va_list args, t_option *opt)
{
	int	char_arg;

	char_arg = va_arg(args, int);
	while (opt->wid-- > 1)
		ft_putchar_count(' ', opt);
	ft_putchar_count(char_arg, opt);
}

void	ft_printf_char(va_list args, t_option *opt)
{
	int	char_arg;

	char_arg = 0;
	if (opt->wid == 0 && opt->dash == 0 && opt->zero == 0
		&& opt->prec == -1)
	{
		char_arg = va_arg(args, int);
		ft_putchar_count(char_arg, opt);
	}
	else if (opt->dash == 0 && opt->zero == 0 && opt->prec == -1)
		print_wi_char(args, opt);
	else if (opt->dash == 1 && opt->zero == 0 && opt->prec == -1)
		print_wi_dash_char(args, opt);
	ft_reset_opt(opt);
}
