/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:27:34 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 13:19:43 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	print_wp_dash_perc(t_option *opt, char pave)
{
	if (opt->prec >= 0 && opt->wid == 0)
		ft_putchar_count('%', opt);
	else
	{
		ft_putchar_count('%', opt);
		while (opt->wid-- > 1)
			ft_putchar_count(pave, opt);
	}
}

static void	print_wp_percent(t_option *opt, char pave)
{
	if (opt->prec >= 0 && opt->wid == 0)
		ft_putchar_count('%', opt);
	else
	{
		while (opt->wid-- > 1)
			ft_putchar_count(pave, opt);
		ft_putchar_count('%', opt);
	}
}

void	ft_printf_percent(t_option *opt)
{
	char	pave;

	if (opt->zero == 1 && opt->dash == 0)
		pave = '0';
	else
		pave = ' ';
	if (opt->dash == 0)
		print_wp_percent(opt, pave);
	else
		print_wp_dash_perc(opt, pave);
	ft_reset_opt(opt);
}
