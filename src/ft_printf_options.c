/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 22:17:45 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 01:03:17 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_reset_opt(t_option *opt)
{
	opt->aux_pos = 0;
	opt->hexa = ' ';
}

void	init_options(t_option *opt)
{
	opt->posit = 0;
	opt->aux_pos = 0;
	opt->count = 0;
	opt->hexa = ' ';
}
