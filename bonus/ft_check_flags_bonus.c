/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:07:32 by apires-d          #+#    #+#             */
/*   Updated: 2021/07/20 00:38:11 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	ft_check_dash(const char *format, t_option *opt)
{
	if (format[opt->posit] == '-')
	{
		opt->posit++;
		if (!(format[opt->posit] == '-'))
			return (1);
		else
		{
			while (format[opt->posit] == '-')
				opt->posit++;
			return (1);
		}
	}
	else
		return (0);
}

static int	ft_check_zero(const char *format, t_option *opt)
{
	if (format[opt->posit] == '0')
	{
		opt->posit++;
		return (1);
	}
	else
		return (0);
}

static void	ft_check_width(const char *format, t_option *opt)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_calloc(11, sizeof(char));
	if (aux)
	{
		while (ft_isdigit(format[opt->posit]))
		{
			aux[i] = format[opt->posit];
			i++;
			opt->posit++;
		}
		opt->wid = ft_atoi(aux);
		free(aux);
	}
}

static void	ft_check_precision(const char *format, t_option *opt)
{
	char	*aux;
	int		i;

	i = 0;
	if (format[opt->posit] == '.')
	{
		opt->posit++;
		aux = ft_calloc(11, sizeof(char));
		if (aux)
		{
			while (ft_isdigit(format[opt->posit]))
			{
				aux[i] = format[opt->posit];
				i++;
				opt->posit++;
			}
			opt->prec = ft_atoi(aux);
		}
		free(aux);
	}
}

void	ft_check_flags(const char *format, t_option *opt)
{
	if (ft_check_zero(format, opt) == 1)
		opt->zero++;
	if (ft_check_dash(format, opt) == 1)
		opt->dash++;
	ft_check_width(format, opt);
	ft_check_precision(format, opt);
}
