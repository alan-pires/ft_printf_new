/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 20:57:20 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 14:50:33 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_str(va_list args, t_option *opt)
{
	char	*str_arg;

	str_arg = va_arg(args, char *);
	if (!str_arg)
		ft_putstr_count("(null)", opt);
	else
		ft_putstr_count(str_arg, opt);
}
