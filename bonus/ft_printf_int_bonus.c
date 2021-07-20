/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:14:10 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 00:38:22 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	print_pw_int(va_list args, t_option *opt)
{
	int	len;
	int	int_arg;

	int_arg = va_arg(args, int);
	len = ft_len_nbr(int_arg);
	if (opt->prec == 0 && int_arg == 0)
		print_prec_zero(int_arg, opt);
	else
	{
		if (int_arg < 0)
			opt->wid--;
		fill_width(opt, len);
		if (int_arg < 0)
			ft_putchar_count('-', opt);
		while (opt->prec-- > len)
			ft_putchar_count('0', opt);
		ft_putnbr_count(int_arg, opt);
	}
}

static void	print_prec_int(va_list args, t_option *opt)
{
	int	len;
	int	int_arg;

	int_arg = va_arg(args, int);
	len = ft_len_nbr(int_arg);
	if (opt->prec == 0 && int_arg == 0)
		ft_putstr_fd("", 1);
	else
	{
		if (int_arg < 0)
			ft_putchar_count('-', opt);
		while (opt->prec-- > len)
			ft_putchar_count('0', opt);
		ft_putnbr_count(int_arg, opt);
	}
}

static void	print_wi_dash_int(va_list args, t_option *opt)
{
	int	len;
	int	int_arg;

	int_arg = va_arg(args, int);
	if (int_arg >= 0)
		len = ft_len_nbr(int_arg);
	else
		len = ft_len_nbr(int_arg) + 1;
	if (int_arg < 0)
		ft_putchar_count('-', opt);
	ft_putnbr_count(int_arg, opt);
	if (opt->wid > len)
	{
		while (len++ < opt->wid)
			ft_putchar_count(' ', opt);
	}
}

static void	print_wi_ze_int(va_list args, t_option *opt, char pave)
{
	int	len;
	int	int_arg;

	int_arg = va_arg(args, int);
	if (int_arg >= 0)
		len = ft_len_nbr(int_arg);
	else
		len = ft_len_nbr(int_arg) + 1;
	if (int_arg >= 0)
		print_wid(opt, len, int_arg);
	else
	{
		if (pave == ' ')
		{
			while (opt->wid-- > len)
				ft_putchar_count(pave, opt);
			ft_putchar_count('-', opt);
			ft_putnbr_count(int_arg, opt);
		}
		else
		{
			ft_putchar_count('-', opt);
			print_wid(opt, len, int_arg);
		}
	}
}

void	ft_printf_int(const char *str, va_list args, t_option *opt)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] == '%')
	{
		if (opt->wid >= 0 && opt->dash == 0 && opt->prec == -1
			&& opt->zero == 0)
			print_wi_ze_int(args, opt, ' ');
		if (opt->wid >= 0 && opt->dash == 1 && opt->prec == -1)
			print_wi_dash_int(args, opt);
		if (opt->zero == 1 && opt->dash == 0 && opt->wid >= 0
			&& opt->prec == -1)
			print_wi_ze_int(args, opt, '0');
		if (opt->prec >= 0 && opt->dash == 0 && opt->wid == 0)
			print_prec_int(args, opt);
		if (opt->prec >= 0 && opt->dash == 0 && opt->wid > 0)
			print_pw_int(args, opt);
		if (opt->prec >= 0 && opt->dash == 1)
			print_pw_int_dash(args, opt);
	}
	ft_reset_opt(opt);
}
