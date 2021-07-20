/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:58:33 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 11:53:52 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_option
{
	int		posit;
	int		aux_pos;
	int		count;
	char	hexa;
}			t_option;

int			ft_printf(const char *format, ...);
void		ft_printf_char(va_list args, t_option *opt);
void		ft_printf_str(va_list args, t_option *opt);
void		ft_printf_int(va_list args, t_option *opt);
void		ft_printf_unsi_int(va_list args, t_option *opt);
void		ft_printf_unsi_hex(va_list args, t_option *opt);
void		ft_printf_point(va_list args, t_option *opt);
void		ft_printf_percent(t_option *opt);
void		ft_send_format(const char *format, va_list args, t_option *opt);
void		ft_putnbr_count(int n, t_option *opt);
void		ft_putstr_count(const char *s, t_option *opt);
void		ft_putchar_count(char c, t_option *opt);
void		ft_put_unsi_count(unsigned int n, t_option *opt);
void		ft_reset_opt(t_option *opt);
void		init_options(t_option *opt);

#	endif