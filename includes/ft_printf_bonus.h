/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:58:33 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 15:17:50 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_option
{
	int		wid;
	int		posit;
	int		zero;
	int		dash;
	int		prec;
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
void		ft_check_flags(const char *format, t_option *opt);
void		ft_send_format(const char *format, va_list args, t_option *opt);
void		ft_putnbr_count(int n, t_option *opt);
void		ft_putstr_count(const char *s, t_option *opt);
void		ft_putchar_count(char c, t_option *opt);
void		ft_put_unsi_count(unsigned int n, t_option *opt);
void		ft_reset_opt(t_option *opt);
void		init_options(t_option *opt);
int			ft_check_errors(const char *format, t_option *opt );
void		print_prec_zero(int int_arg, t_option *opt);
int			ft_len_unsi(unsigned int n);
void		ft_put_hex_count(unsigned int nbr, t_option *opt);
char		*ft_inttohex(unsigned int nbr, t_option *opt);
void		fill_width(t_option *opt, int len);
char		*ft_uinttohex(unsigned int nbr, t_option *opt);
char		*ft_lltohex(unsigned long nbr);
void		print_wid(t_option *opt, int len, int int_arg);
void		print_pw_int_dash(va_list args, t_option *opt);
void		print_pw_uhex_dash(va_list args, t_option *opt);
void		print_pw_uint_dash(va_list args, t_option *opt);
void		print_pw_dash_str(va_list args, t_option *opt);
long long	ft_len_long(long long n);
void		ft_fill_len(void *arg, char *len);

#	endif