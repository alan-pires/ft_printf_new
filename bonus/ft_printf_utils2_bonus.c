/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:07:07 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 11:41:03 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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

void	ft_put_unsi_count(unsigned int n, t_option *opt)
{
	unsigned int	num;

	num = n;
	if (num >= 10)
		ft_put_unsi_count(num / 10, opt);
	ft_putchar_count((char)(num % 10 + '0'), opt);
}

void	print_prec_zero(int int_arg, t_option *opt)
{
	if (opt->prec == 0 && int_arg == 0)
	{
		if (opt->dash == 1)
		{
			while (opt->wid-- > opt->prec)
				ft_putchar_count(' ', opt);
			ft_putstr_fd("", 1);
		}
		else if (opt->dash == 0)
		{
			ft_putstr_fd("", 1);
			while (opt->wid-- > opt->prec)
				ft_putchar_count(' ', opt);
		}
	}
}

char	*ft_uinttohex(unsigned int nbr, t_option *opt)
{
	char			*hex_alg;
	char			*str;
	unsigned int	tmp;
	unsigned int	size;

	if (opt->hexa == 'x')
		hex_alg = ft_strdup("0123456789abcdef");
	else if (opt->hexa == 'X')
		hex_alg = ft_strdup("0123456789ABCDEF");
	size = 0;
	tmp = nbr;
	while (tmp > 0)
	{
		tmp /= 16;
		size++;
	}
	str = malloc(size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size-- - 1] = hex_alg[nbr % 16];
		nbr = nbr / 16;
	}
	free(hex_alg);
	return (str);
}

char	*ft_lltohex(unsigned long nbr)
{
	char				*hex_alg;
	char				*str;
	unsigned long		tmp;
	unsigned long		size;

	hex_alg = ft_strdup("0123456789abcdef");
	size = 0;
	tmp = nbr;
	while (tmp > 0)
	{
		tmp /= 16;
		size++;
	}
	str = malloc(size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = hex_alg[nbr % 16];
		size--;
		nbr = nbr / 16;
	}
	free(hex_alg);
	return (str);
}
