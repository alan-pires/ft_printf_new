/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 20:57:20 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 13:20:01 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	print_pw_str(va_list args, t_option *opt)
{
	int		i;
	int		len;
	char	*str_arg;

	i = -1;
	str_arg = va_arg(args, char *);
	if (!str_arg)
		str_arg = "(null)";
	len = ft_strlen(str_arg);
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
	while (++i < opt->prec && i < len)
		ft_putchar_count(str_arg[i], opt);
}

static void	print_wi_dash_str(va_list args, t_option *opt)
{
	int		len;
	char	*str_arg;

	str_arg = va_arg(args, char *);
	len = ft_strlen(str_arg);
	ft_putstr_count(str_arg, opt);
	if (opt->wid > len)
		while (len++ < opt->wid)
			ft_putchar_count(' ', opt);
}

static void	print_wi_str(va_list args, t_option *opt)
{
	int		len;
	char	*str_arg;

	str_arg = va_arg(args, char *);
	if (!str_arg)
		len = 6;
	else
		len = ft_strlen(str_arg);
	while (opt->wid-- > len)
		ft_putchar_count(' ', opt);
	if (!str_arg)
		ft_putstr_count("(null)", opt);
	else
		ft_putstr_count(str_arg, opt);
}

void	print_str(va_list args, t_option *opt)
{
	char	*str_arg;

	str_arg = va_arg(args, char *);
	if (!str_arg)
		ft_putstr_count("(null)", opt);
	else
		ft_putstr_count(str_arg, opt);
}

void	ft_printf_str(va_list args, t_option *opt)
{
	if (opt->wid == 0 && opt->zero == 0
		&& opt->prec == -1)
		print_str(args, opt);
	if (opt->wid > 0 && opt->dash == 0 && opt->prec == -1 && opt->zero == 0)
		print_wi_str(args, opt);
	if (opt->wid > 0 && opt->dash == 1 && opt->prec == -1 && opt->zero == 0)
		print_wi_dash_str(args, opt);
	if (opt->prec >= 0 && opt->dash == 0 && opt->zero == 0)
		print_pw_str(args, opt);
	if (opt->prec >= 0 && opt->dash == 1 && opt->zero == 0)
		print_pw_dash_str(args, opt);
	ft_reset_opt(opt);
}
