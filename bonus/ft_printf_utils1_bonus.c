/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:07:07 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 00:41:06 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_putchar_count(char c, t_option *opt)
{
	write(1, &c, 1);
	opt->count++;
}

void	ft_putstr_count(const char *s, t_option *opt)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_count(*s, opt);
			s++;
		}
	}
}

void	fill_width(t_option *opt, int len)
{	
	if (opt->prec > len)
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

void	print_wid(t_option *opt, int len, int int_arg)
{
	char	pave;

	if (opt->zero > 0)
		pave = '0';
	else
		pave = ' ';
	while (opt->wid-- > len)
		ft_putchar_count(pave, opt);
	ft_putnbr_count(int_arg, opt);
}

long long	ft_len_long(long long n)
{
	long long	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
