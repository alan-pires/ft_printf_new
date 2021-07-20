/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsi_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 09:16:16 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 01:03:11 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_uinttohex(unsigned int nbr, t_option *opt)
{
	char			*hex_alg;
	char			*str;
	unsigned int	tmp;
	int				size;

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

void	ft_printf_unsi_hex(va_list args, t_option *opt)
{
	unsigned int	uhex_arg;
	char			*hex_arg;

	uhex_arg = va_arg(args, unsigned int);
	hex_arg = ft_uinttohex(uhex_arg, opt);
	if (uhex_arg == 0)
		ft_putchar_count('0', opt);
	else
		ft_putstr_count(hex_arg, opt);
	free(hex_arg);
	ft_reset_opt(opt);
}
