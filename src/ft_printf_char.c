/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:47:22 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 01:03:19 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_char(va_list args, t_option *opt)
{
	int	char_arg;

	char_arg = va_arg(args, int);
	ft_putchar_count(char_arg, opt);
	ft_reset_opt(opt);
}
