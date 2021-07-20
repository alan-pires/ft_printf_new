/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:31:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 13:19:51 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	print_neg_point(char *arg, t_option *opt)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		arg[i] = 'f';
		i++;
	}
	ft_putstr_count("0x", opt);
	ft_putstr_count(arg, opt);
}

static void	print_wi_dash_point(va_list args, t_option *opt)
{
	int				len;
	unsigned long	p_arg;
	char			*hex_arg;

	p_arg = va_arg(args, unsigned long);
	hex_arg = ft_lltohex(p_arg);
	len = ft_strlen(hex_arg);
	if (p_arg && p_arg > 0)
	{
		ft_putstr_count("0x", opt);
		ft_putstr_count(hex_arg, opt);
	}
	else if (p_arg == 0)
		ft_putstr_count("0x0", opt);
	else
	{
		len = 16;
		print_neg_point(hex_arg, opt);
	}
	while (opt->wid-- > len + 2)
		ft_putchar_count(' ', opt);
	free(hex_arg);
}

static void	print_wi_point(va_list args, t_option *opt)
{
	int				len;
	unsigned long	p_arg;
	char			*hex_arg;

	p_arg = va_arg(args, unsigned long);
	hex_arg = ft_lltohex(p_arg);
	len = ft_strlen(hex_arg) + 2;
	if (p_arg && p_arg > 0)
	{
		while (opt->wid-- > len)
			ft_putchar_count(' ', opt);
		ft_putstr_count("0x", opt);
		ft_putstr_count(hex_arg, opt);
	}
	else
	{
		while (opt->wid-- > 3)
			ft_putchar_count(' ', opt);
		ft_putstr_count("0x0", opt);
	}
	free(hex_arg);
}

static void	print_point(va_list args, t_option *opt)
{
	unsigned long	p_arg;
	char			*hex_arg;

	p_arg = va_arg(args, unsigned long);
	hex_arg = ft_lltohex(p_arg);
	if (p_arg && p_arg > 0)
	{
		ft_putstr_count("0x", opt);
		ft_putstr_count(hex_arg, opt);
	}
	else if (p_arg == 0)
		ft_putstr_count("0x0", opt);
	else
		print_neg_point(hex_arg, opt);
	free(hex_arg);
}

void	ft_printf_point(va_list args, t_option *opt)
{
	if (opt->wid == 0 && opt->dash == 0 && opt->zero == 0
		&& opt->prec == -1)
		print_point(args, opt);
	else if (opt->wid >= 0 && opt->dash == 0)
		print_wi_point(args, opt);
	else if (opt->wid >= 0 && opt->dash == 1)
		print_wi_dash_point(args, opt);
	ft_reset_opt(opt);
}
