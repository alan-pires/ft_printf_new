/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:07:07 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 01:03:06 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	ft_putnbr_count(int n, t_option *opt)
{
	unsigned int	num;

	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr_count(num / 10, opt);
	ft_putchar_count((char)(num % 10 + '0'), opt);
}
