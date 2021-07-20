/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:31:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 16:27:18 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

static char	*ft_lltohex(unsigned long nbr)
{
	char			*hex_alg;
	char			*str;
	unsigned long	tmp;
	unsigned long	size;

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

void	ft_printf_point(va_list args, t_option *opt)
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
