/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 22:17:45 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 00:38:45 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_reset_opt(t_option *opt)
{
	opt->dash = 0;
	opt->zero = 0;
	opt->wid = 0;
	opt->prec = -1;
	opt->aux_pos = 0;
	opt->hexa = ' ';
}

void	init_options(t_option *opt)
{
	opt->dash = 0;
	opt->zero = 0;
	opt->wid = 0;
	opt->posit = 0;
	opt->prec = -1;
	opt->aux_pos = 0;
	opt->count = 0;
	opt->hexa = ' ';
}
