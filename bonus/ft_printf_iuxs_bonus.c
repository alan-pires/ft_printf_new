/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_iuxs_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:53:28 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 00:45:31 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	fill_wid_pwd(t_option *opt, int len)
{
	if (len > opt->prec)
	{
		while (opt->wid > opt->prec && opt->wid-- > len)
			ft_putchar_count(' ', opt);
	}
	else
	{
		while (opt->wid-- > opt->prec && opt->wid > len)
			ft_putchar_count(' ', opt);
	}
}

void	print_pw_int_dash(va_list args, t_option *opt)
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
			ft_putchar_count('-', opt);
		while (len++ < opt->prec)
			ft_putchar_count('0', opt);
		len = ft_len_nbr(int_arg);
		ft_putnbr_count(int_arg, opt);
		if (int_arg < 0 && opt->prec > len)
			opt->wid--;
		fill_wid_pwd(opt, len);
	}
}

void	print_pw_uhex_dash(va_list args, t_option *opt)
{
	int	len;
	unsigned int	uhex_arg;
	char			*hex_arg;

	uhex_arg = va_arg(args, unsigned int);
	hex_arg = ft_uinttohex(uhex_arg, opt);
	len = ft_strlen(hex_arg);
	if (opt->prec == 0 && uhex_arg == 0)
		print_prec_zero((int)uhex_arg, opt);
	else if (opt->wid > opt->prec)
	{
		while (len++ < opt->prec)
			ft_putchar_count('0', opt);
		ft_putstr_count(hex_arg, opt);
		len = ft_strlen(hex_arg);
		fill_width(opt, len);
	}
	else
	{
		while (opt->prec-- > len)
			ft_putchar_count('0', opt);
		ft_putstr_count(hex_arg, opt);
	}
	free(hex_arg);
}

void	print_pw_uint_dash(va_list args, t_option *opt)
{
	int	len;
	unsigned int	uint_arg;

	uint_arg = va_arg(args, unsigned int);
	len = ft_len_uns_nbr(uint_arg);
	if (opt->prec == 0 && uint_arg == 0)
		print_prec_zero((int)uint_arg, opt);
	else
	{
		while (len++ < opt->prec)
			ft_putchar_count('0', opt);
		ft_put_unsi_count(uint_arg, opt);
		len = ft_len_uns_nbr(uint_arg);
		fill_width(opt, len);
	}
}

void	print_pw_dash_str(va_list args, t_option *opt)
{
	int		i;
	int		len;
	char	*str_arg;

	i = -1;
	str_arg = va_arg(args, char *);
	len = ft_strlen(str_arg);
	while (++i < opt->prec && i < len)
		ft_putchar_count(str_arg[i], opt);
	if (opt->prec < len)
	{
		while (opt->wid-- > opt->prec)
			ft_putchar_count(' ', opt);
	}
	else
	{
		while (opt->wid-- > len)
			ft_putchar_count(' ', opt);
	}
}
