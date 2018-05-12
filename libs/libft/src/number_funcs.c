/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:21:01 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 16:52:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fetch_arg(t_arg_info *inf, int arg_nb)
{
	int	i;

	i = 0;
	while (++i <= arg_nb - inf->arg_f)
		va_arg(inf->args_ref, uintmax_t);
	return (va_arg(inf->args_ref, int));
}

int			p_parse_number(t_arg_info *inf)
{
	int	ret;

	ret = 0;
	while (ft_isdigit(inf->fmt_ref[ret]))
		ret++;
	if (inf->fmt_ref[ret] == '$')
	{
		inf->arg_i = ft_atoi(inf->fmt_ref) - 1 - inf->arg_f;
		ret++;
	}
	else
		inf->field_width_val = ft_atoi(inf->fmt_ref);
	return (ret);
}

static int	asterisk_precision(t_arg_info *inf)
{
	int	ret;
	int	arg_nb;

	ret = 2;
	while (ft_isdigit(inf->fmt_ref[ret]))
		ret++;
	if (inf->fmt_ref[ret] == '$')
	{
		arg_nb = ft_atoi(&inf->fmt_ref[2]);
		inf->precision_val = (arg_nb == 0 ? 0 : fetch_arg(inf, arg_nb - 1));
		ret++;
	}
	else
	{
		inf->precision_val = fetch_arg(inf, inf->arg_i);
		inf->arg_i++;
		ret = 2;
	}
	if (inf->precision_val < 0)
		inf->precision_val = -1;
	else
		inf->flags |= F_PRECISION_ON;
	return (ret);
}

int			p_precision_flag(t_arg_info *inf)
{
	int	ret;

	ret = 1;
	if (inf->fmt_ref[ret] == '*')
		return (asterisk_precision(inf));
	inf->flags |= F_PRECISION_ON;
	while (ft_isdigit(inf->fmt_ref[ret]))
		ret++;
	inf->precision_val = ft_atoi(&inf->fmt_ref[1]);
	return (ret);
}

int			p_asterisk_width_flag(t_arg_info *inf)
{
	int	ret;
	int	arg_nb;

	ret = 1;
	while (ft_isdigit(inf->fmt_ref[ret]))
		ret++;
	if (inf->fmt_ref[ret] == '$')
	{
		arg_nb = ft_atoi(&inf->fmt_ref[1]);
		inf->field_width_val = (arg_nb == 0 ? 0 : fetch_arg(inf, arg_nb - 1));
		ret++;
	}
	else
	{
		inf->field_width_val = fetch_arg(inf, inf->arg_i);
		inf->arg_i++;
		ret = 1;
	}
	if (inf->field_width_val < 0)
	{
		inf->field_width_val = -inf->field_width_val;
		inf->flags |= F_NEGATIVE_FIELD;
	}
	return (ret);
}
