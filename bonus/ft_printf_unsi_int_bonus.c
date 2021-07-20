/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsi_int_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:51:54 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 13:11:41 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	print_pw_uint(va_list args, t_option *opt)
{
	int				len;
	unsigned int	uint_arg;

	uint_arg = va_arg(args, unsigned int);
	len = ft_len_uns_nbr(uint_arg);
	if (opt->prec == 0 && uint_arg == 0)
		print_prec_zero((int)uint_arg, opt);
	else
	{
		fill_width(opt, len);
		while (opt->prec-- > len)
			ft_putchar_count('0', opt);
		ft_put_unsi_count(uint_arg, opt);
	}
}

static void	print_prec_uint(va_list args, t_option *opt)
{
	int				len;
	unsigned int	uint_arg;

	uint_arg = va_arg(args, unsigned int);
	len = ft_len_uns_nbr(uint_arg);
	if (opt->prec == 0 && uint_arg == 0)
		ft_putstr_fd("", 1);
	else
	{
		while (opt->prec-- > len)
			ft_putchar_count('0', opt);
		ft_put_unsi_count(uint_arg, opt);
	}
}

static void	print_wi_dash_uint(va_list args, t_option *opt)
{
	int				len;
	unsigned int	uint_arg;

	uint_arg = va_arg(args, unsigned int);
	len = ft_len_uns_nbr(uint_arg);
	ft_put_unsi_count(uint_arg, opt);
	if (opt->wid > len)
		while (len++ < opt->wid)
			ft_putchar_count(' ', opt);
}

static void	print_wi_ze_uint(va_list args, t_option *opt, char pave)
{
	int				len;
	unsigned int	uint_arg;

	uint_arg = va_arg(args, unsigned int);
	len = ft_len_uns_nbr(uint_arg);
	while (opt->wid-- > len)
		ft_putchar_count(pave, opt);
	ft_put_unsi_count(uint_arg, opt);
}

void	ft_printf_unsi_int(const char *str, va_list args, t_option *opt)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] == '%')
	{
		if (opt->wid >= 0 && opt->dash == 0 && opt->prec == -1
			&& opt->zero == 0)
			print_wi_ze_uint(args, opt, ' ');
		if (opt->wid >= 0 && opt->dash == 1 && opt->prec == -1)
			print_wi_dash_uint(args, opt);
		if (opt->zero == 1 && opt->dash == 0 && opt->wid >= 0
			&& opt->prec == -1)
			print_wi_ze_uint(args, opt, '0');
		if (opt->prec >= 0 && opt->dash == 0 && opt->wid == 0)
			print_prec_uint(args, opt);
		if (opt->prec >= 0 && opt->dash == 0 && opt->wid > 0)
			print_pw_uint(args, opt);
		if (opt->prec >= 0 && opt->dash == 1)
			print_pw_uint_dash(args, opt);
	}
	ft_reset_opt(opt);
}
