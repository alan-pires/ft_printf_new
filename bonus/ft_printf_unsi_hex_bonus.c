/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsi_hex_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 09:16:16 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 00:40:35 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	print_pw_uhex(va_list args, t_option *opt)
{
	int	len;
	unsigned int	uhex_arg;
	char			*hex_arg;

	uhex_arg = va_arg(args, unsigned int);
	hex_arg = ft_uinttohex(uhex_arg, opt);
	len = ft_strlen(hex_arg);
	if (opt->prec == 0 && uhex_arg == 0)
		print_prec_zero((int)uhex_arg, opt);
	else if (opt->prec > len)
	{
		while (opt->wid-- > opt->prec)
			ft_putchar_count(' ', opt);
		while (opt->prec-- > len)
			ft_putchar_count('0', opt);
		ft_putstr_count(hex_arg, opt);
	}
	else
	{
		fill_width(opt, len);
		ft_putstr_count(hex_arg, opt);
	}
	free(hex_arg);
}

static void	print_prec_uhex(va_list args, t_option *opt)
{
	int	len;
	unsigned int	uhex_arg;
	char			*hex_arg;

	uhex_arg = va_arg(args, unsigned int);
	hex_arg = ft_uinttohex(uhex_arg, opt);
	len = ft_strlen(hex_arg);
	if (opt->prec == 0 && uhex_arg == 0)
		ft_putstr_fd("", 1);
	else if (opt->prec > len)
	{
		while (opt->prec-- > len)
			ft_putchar_count('0', opt);
		ft_putstr_count(hex_arg, opt);
	}
	else
		ft_putstr_count(hex_arg, opt);
	free(hex_arg);
}

static void	print_wi_dash_uhex(va_list args, t_option *opt)
{
	int	len;
	unsigned int	uhex_arg;
	char			*hex_arg;

	uhex_arg = va_arg(args, unsigned int);
	hex_arg = ft_uinttohex(uhex_arg, opt);
	len = ft_strlen(hex_arg);
	if (uhex_arg == 0)
	{
		len = 1;
		ft_putchar_count('0', opt);
	}
	else
		ft_putstr_count(hex_arg, opt);
	while (opt->wid-- > len)
		ft_putchar_count(' ', opt);
	free(hex_arg);
}

static void	print_wi_ze_uhex(va_list args, t_option *opt, char pave)
{
	int	len;
	unsigned int	uhex_arg;
	char			*hex_arg;

	uhex_arg = va_arg(args, unsigned int);
	hex_arg = ft_uinttohex(uhex_arg, opt);
	len = ft_strlen(hex_arg);
	if (uhex_arg == 0)
		ft_putchar_count('0', opt);
	else
	{
		while (opt->wid-- > len)
			ft_putchar_count(pave, opt);
		ft_putstr_count(hex_arg, opt);
	}
	free(hex_arg);
}

void	ft_printf_unsi_hex(const char *str, va_list args, t_option *opt)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] == '%')
	{
		if (opt->wid >= 0 && opt->dash == 0 && opt->prec == -1
			&& opt->zero == 0)
			print_wi_ze_uhex(args, opt, ' ');
		if (opt->wid >= 0 && opt->dash == 1 && opt->prec == -1)
			print_wi_dash_uhex(args, opt);
		if (opt->zero == 1 && opt->dash == 0 && opt->wid >= 0
			&& opt->prec == -1)
			print_wi_ze_uhex(args, opt, '0');
		if (opt->prec >= 0 && opt->dash == 0 && opt->wid == 0)
			print_prec_uhex(args, opt);
		if (opt->prec >= 0 && opt->dash == 0 && opt->wid > 0)
			print_pw_uhex(args, opt);
		if (opt->prec >= 0 && opt->dash == 1)
			print_pw_uhex_dash(args, opt);
	}
	ft_reset_opt(opt);
}
